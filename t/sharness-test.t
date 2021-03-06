#!/bin/sh
set -x

pth=`pwd`


test_description="Test the requirements for the CWD"


. ./sharness.sh


pth2=`pwd`


test_debug '
   echo "After: $pth2" &&
   echo "Before: $pth"
'

test_expect_success 'CWD basename is qualified' '
   pushd $pth &&
   ./t1 &&
   popd
'

test_expect_success "Paths leading to CWD is shallow enough" '
    pushd $pth &&
    ./t2 &&
    popd	
'

test_expect_success "Parent directory name is qualified" '
    pushd $pth &&
    ./t3 && 
    popd
'

test_expect_success "Num of files too small" '
    pushd $pth &&
    ./t4 &&
    popd
'

test_expect_failure "Failure test" '
    ../t1
'

test_done

# vi: set ft=sh :
