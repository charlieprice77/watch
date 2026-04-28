#!/bin/bash

LOG_FILE="build.log"
NCS_DIR=~/ncs/v3.2.2
APP_DIR=$(pwd)

nrfutil sdk-manager toolchain launch --ncs-version v3.2.2 --chdir "$NCS_DIR" -- west build --pristine \
	-b "nrf54l15dk/nrf54l15/cpuapp" \
	-s "$APP_DIR" \
	-- -DBOARD_ROOT="$APP_DIR" 2>&1 | tee "$LOG_FILE"

EXIT_CODE=${PIPESTATUS[0]}
echo ""
echo "--- buiild summary ---"
grep -E "(error: |warning: |FAILED|ninja:)" "$LOG_FILE" | grep -v "^--" | head -60
exit $EXIT_CODE
