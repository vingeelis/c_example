#!/usr/bin/env bash
#

find . -type f | xargs -I{} file {} | awk -F: '/ELF 64-bit LSB shared object/{print $1}' | xargs -I{} rm -rf {}