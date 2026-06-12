#!/bin/bash

case "$1" in
  build)
    bison -d lisp.y && flex lisp.l && gcc lisp.tab.c lex.yy.c;;
  run)
    ./a.out < input > output.html;;
  test)
    firefox output.html;;
  *)
    echo "Usage: $0 {build|run|test}"
    exit 1;;
esac
