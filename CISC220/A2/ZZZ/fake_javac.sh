#!/bin/bash
#
# compile.sh: fake compilation of a Java source code file
#
# Usage: compile.sh java-filename

java="$1"
case "$java" in
  "")
    echo "Usage: compile.sh java-filename" >&2
    exit 2
    ;;
  Test1.java | Test2.java)
    exit 0
    ;;
  Test3.java)
    echo "Test3.java: error: ';' expected" >&2
    exit 1
    ;;
  *)
    status=$(( $RANDOM % 2 ))
    if (( status != 0 )); then
      echo "${java}: some random syntax error"
    fi
    exit $status
    ;;
esac
