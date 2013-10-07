// ---------------------------------------------------------------------- 
// archive: file maintainer
// ---------------------------------------------------------------------- 

#include "st.h"

#define MAXFILES 10

typedef enum {
  UPDATE = 'u',
  TABLE = 't',
  EXTRACT = 'e',
  PRINT = 'p',
  DELETE = 'd'
} COMMAND;

char fname[MAXFILES][NAMESIZE];
bool_t fstat[MAXFILES];
size_t nfiles = 0, errcnt = 0;
const STR const hdr = "-h-";

// ---------------------------------------------------------------------- 
// help: diagnostic printout
// ---------------------------------------------------------------------- 
void help() {
  fprintf(stderr, "%s\n", "usage: archive {dptux} archname [files].");
  exit(1);
}

// ---------------------------------------------------------------------- 
// makhdr: make header line for archive member
// ---------------------------------------------------------------------- 
void makhdr(const STR const name, STR const head) {
  str_scopy(hdr, 1, head, 1);
  size_t i = str_length(hdr) + 1;
  STR_AT(head, i) = BLANK;
  str_scopy(name, 1, head, i + 1);
  i = str_length(head) + 1;
  STR_AT(head, i) = BLANK;
  i = i + 1 + str_itoc(io_fsize(name), &STR_AT(head, i+1), MAXCHARS);
  STR_AT(head, i) = NEWLINE;
  STR_AT(head, i+1) = EOS;
}

// ---------------------------------------------------------------------- 
// addfil: add file "name" to archive
// ---------------------------------------------------------------------- 
void addfil(const STR const name, FILE *const fd) {
  FILE *const nfd = io_open(name, READ);
  if (nfd == NULL) {
    io_putlin(name, stderr);
    remark(": can't add.");
    ++errcnt;
  }
  if (errcnt == 0) {
    char head[MAXLINE];
    makhdr(name, head);
    io_putlin(head, fd);
    io_fcopy(nfd, fd);
    fclose(nfd);
  }
}

// ---------------------------------------------------------------------- 
// gethdr: get header info from fd
// ---------------------------------------------------------------------- 
bool_t gethdr(FILE *const fd, STR const buf, STR const name,
    size_t *const size) {
  char temp[NAMESIZE];

  if (io_getlin(buf, fd, MAXLINE) >= MAXLINE)
    return NO;
  size_t i = 1;
  size_t len = str_getwrd(buf, &i, temp);
  if (str_equal(temp, hdr) == NO)
    error("archive not in proper format.");
  str_getwrd(buf, &i, name);
  *size = str_ctoi(buf, &i);
  return YES;
}

// ---------------------------------------------------------------------- 
// filarg: check if name matches argument list
// ---------------------------------------------------------------------- 
bool_t filarg(const STR const name) {
  if (nfiles <= 0)
    return YES;
  for (size_t i = 1; i <= nfiles; ++i)
    if (str_equal(name, ARR_AT(fname, i)) == YES) {
      ARR_AT(fstat, i) = YES;
      return YES;
    }
  return NO; 
}

// ---------------------------------------------------------------------- 
// acopy: copy size characters from fdi to fdo
// ---------------------------------------------------------------------- 
void acopy(FILE *const fdi, FILE *const fdo, size_t size) {
  int c;
  for (size_t i = 1; i <= size; ++i) {
    if (GETCH(c, fdi) == EOF)
      break;
    PUTCH(c, fdo);
  } 
}

// ---------------------------------------------------------------------- 
// replac: replace or delete files
// ---------------------------------------------------------------------- 
void replac(FILE *const afd, FILE *const tfd,
    COMMAND cmd) {
  size_t size;
  char in[MAXLINE], uname[NAMESIZE];

  while (gethdr(afd, in, uname, &size) == YES)
    if (filarg(uname) == YES) {
      if (cmd == UPDATE)
        // add new one
        addfil(uname, tfd);
      // discard old one
      fseek(afd, size, SEEK_CUR);
    }
    else {
      io_putlin(in, tfd);
      acopy(afd, tfd, size);
    }
}

// ---------------------------------------------------------------------- 
// update: update existing files, add new ones at end
// ---------------------------------------------------------------------- 
void update(const STR const aname) {
  const STR const tname = "archtemp";
  FILE *afd = io_open(aname, READWRITE);
  if (afd == NULL)
    // maybe it's a new one
    afd = io_create(aname, READWRITE); 
  if (afd == NULL)
    io_cant(aname);
  FILE *const tfd = io_create(tname, READWRITE);
  if (tfd == NULL)
    io_cant(tname);
  // update existing  
  replac(afd, tfd, UPDATE);
  // add new ones
  for (size_t i = 1; i <= nfiles; ++i)
    if (ARR_AT(fstat,i) == NO) {
      addfil(ARR_AT(fname,i), tfd);
      ARR_AT(fstat,i) = YES;
    }
  fclose(afd);
  fclose(tfd);
  if (errcnt == 0)
    rename(tname, aname);
  else
    remark("fatal errors -- archive not altered.");
  remove(tname);
}

// ---------------------------------------------------------------------- 
// getfns: get file names into fname, check for duplicates
// ---------------------------------------------------------------------- 
void getfns() {
  errcnt = 0;
  size_t i, j;
  char buf[1];
  for (i = 1; i <= MAXFILES; ++i)
    if (args_getarg(i+2, ARR_AT(fname, i), NAMESIZE) >= NAMESIZE)
      break;
  nfiles = i - 1;
  if (i > MAXFILES)
    if (args_getarg(i+2, buf, 1) >= 1)
      error("too many file arguments.");
  for (i = 1; i <= nfiles; ++i)
    ARR_AT(fstat, i) = NO;
  for (i = 1; i < nfiles; ++i)
    for (j = i + 1; j <= nfiles; ++j) {
      if (str_equal(ARR_AT(fname, i), ARR_AT(fname, j)) == YES) {
        io_putlin(ARR_AT(fname, i), stderr);
        error(": duplicate file name.");
      }
    }
}

// ----------------------------------------------------------------------
// tprint: print table entry for one member
// ----------------------------------------------------------------------
void tprint(const STR const buf) {
  io_putlin(buf, stdout);
}

// ----------------------------------------------------------------------
// notfnd: print "not found" message
// ----------------------------------------------------------------------
void notfnd() {
  for (size_t i = 1; i <= nfiles; ++i) {
    if (ARR_AT(fstat,i) == NO) {
      io_putlin(STR_AT(fname, i), stderr);
      remark(": not in archive.");
      ++errcnt;
    }
  }
}

// ----------------------------------------------------------------------
// table: print table of archive contents
// ----------------------------------------------------------------------
void table(const STR const aname) {
  char in[MAXLINE], lname[NAMESIZE];
  size_t size;
  FILE *afd = io_open(aname, READ);
  if (afd == NULL)
    io_cant(aname);
  while (gethdr(afd, in, lname, &size) == YES) {
    if (filarg(lname) == YES)
      tprint(in);
    io_fskip(afd, size);
  }
  notfnd();
}

MAIN(
  char aname[NAMESIZE];
  char command[2];

  if (args_getarg(1, command, 2) >= 2
    || args_getarg(2, aname, NAMESIZE) >= NAMESIZE)
    help();
  getfns();
  if (ARR_AT(command, 1) == UPDATE)
    update(aname);
  else if (ARR_AT(command, 1) == TABLE)
    table(aname);
  else
    help();

  return 0;
)
