#!/bin/bash

NCS_DIR=~/ncs/v3.2.2
APP_DIR=$(pwd)

nrfutil sdk-manager toolchain launch --ncs-version v3.2.2 --chdir "$NCS_DIR" -- west flash

EXIT_CODE=${PIPESTATUS[0]}
exit $EXIT_CODE
