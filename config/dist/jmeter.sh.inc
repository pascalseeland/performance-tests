#!/bin/bash

# Configuration of the ILIAS Performance Testsuite
#
# You must restart jMeter for any changes to take effect.
#
# This bash script defines local variables used by `bin/run.sh`,
# `bin\jmeter.sh`, etc.

WORK_DIR=$(pwd) # do not change this, unless necessary

TESTPLAN="testcases/suite.jmx" # TODO: interpret bash parameters $(echo $1; shift)
JMETER_CMD=${WORK_DIR}/apache-jmeter-2.13/bin/jmeter.sh # jMeter Command -- default: jmeter, if in PATH env variable
OUT_DIR="${WORK_DIR}/out"
LOG="${OUT_DIR}/jmeter.log" # may want to add a timestamp YYYY-MM-DD...

##### Save results as CSV or XML #####
# RESULTS="${OUT_DIR}/results.csv"
# PROPFILE="${WORK_DIR}/config/jmeter/csv-results.properties"
RESULTS="${OUT_DIR}/results.xml"
PROPFILE="${WORK_DIR}/config/jmeter/xml-results.properties"
#####

# Each of these KEY=VALUE pairs will be passed to jMeter
# via `--jmeterproperty KEY=VALUE`
JMETER_PROPERTIES=(
  "PROTOCOL=http" # http, https, file
  "HOST=localhost" # domain or ip, e.g. www.ilias.de, localhost, 127.0.0.1
  "PATH=/ilias/trunk/" # must not be empty - e.g. /, /path/to/ilias, /docu, /test51, ..
  "PORT=80" # e.g. 80, 443
  "CLIENT_ID=ilias" # e.g. ilias
  "IS_ADMIN=false" # default: false
  "READ_ONLY=true" # default: true
  OUT_DIR="${OUT_DIR}"

  # Default: Static Credentials
  "USERNAME=" # ILIAS-User
  "PASSWORD=" # ILIAS-Password

  # Alternative: Credentials from CSV
  # "CREDENTIALS_CSV=$WORK_DIR/config/users.csv" # OVERRIDE username and password with values from this CSV file

  #Calendar Properties
  CALENDAR_DATE="" # Date at which the calendar should be opened e.g. 2017-10-12

  #Course Properties
  COURSE_99_SESSIONS_REF_ID="" # Ref-id of a course object with sessions e.g. 11229
  COURSE_99_SESSIONS_NAME=""   # Name of the course above e.g. Course_99_Sessions
  COURSE_50_SESSIONS_REF_ID="" # Ref-id of a course object with sessions e.g. 11291
  COURSE_50_SESSIONS_NAME=""   # Name of the course above e.g. Course_50_Sessions
  COURSE_10_SESSIONS_REF_ID="" # Ref-id of a course object with sessions e.g. 11342
  COURSE_10_SESSIONS_NAME=""   # Name of the course above e.g. Course_10_Sessions

  #Forum Properties
  FORUM_THREADS_NAME="Forum"
  FORUM_10_POSTS_REF_ID=""    # Ref-id of a forum object e.g. 11346
  FORUM_10_POSTS_NAME=""      # Name of the course above e.g. Thread
  FORUM_10_POSTS_THREAD_PK="" # PK of a forum thread e.g. 6
  FORUM_50_POSTS_REF_ID=""    # Ref-id of a forum object e.g. 11346
  FORUM_50_POSTS_NAME=""      # Name of the course above e.g. Thread
  FORUM_50_POSTS_THREAD_PK="" # PK of a forum thread e.g. 6
  FORUM_100_POSTS_REF_ID=""    # Ref-id of a forum object e.g. 11346
  FORUM_100_POSTS_NAME=""      # Name of the course above e.g. Thread
  FORUM_100_POSTS_THREAD_PK="" # PK of a forum thread e.g. 6

  "THREADS=1" # default: 1
  "RAMP_UP=1" # default: 1
  "LOOPS=1" # default: 1
  "WORK_DIR=$WORK_DIR"
)

# Each of these KEY=VALUE pairs will be passed to jMeter
# via `--systemproperty KEY=VALUE`
SYSTEM_PROPERTIES=(
)
