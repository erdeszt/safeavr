#!/bin/bash

set -e

if [ -z "$1" ]; then
    echo "Provide a target"
    exit 1
fi

./scripts/build.sh

pushd build/examples
make "upload_${1}.hex"
popd

