#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

# Download WE-Core
WECORE_HOME="$(cd $SCRIPT_DIR/.. > /dev/null 2>&1 && pwd)"
WECORE_SRC="$WECORE_HOME/WECore"
git clone https://github.com/jd-13/WE-Core $SCRIPT_DIR/../WECore

# We can't download the fonts so create blank files in their place
touch $SCRIPT_DIR/../Source/Graphics/Montserrat-Regular.ttf

# Set JUCE module paths
sed -i 's#../JUCE/modules#/home/JUCE/modules#g' $SCRIPT_DIR/../Richter.jucer

# Generate the makefile
$JUCE_PATH/Projucer --resave $SCRIPT_DIR/../Richter.jucer

# Update the include paths
sed -i 's#-I$(HOME)/WEA/WECore/WECore#-I../../WECore/WECore#g' $SCRIPT_DIR/../Builds/LinuxMakefile/Makefile

# Run the build
cd $SCRIPT_DIR/../Builds/LinuxMakefile
make

# Call pluginval (bus tests don't work on Linux)
cat << EOF >> $SCRIPT_DIR/disabled-tests.txt
Basic bus
EOF

$PLUGINVAL --validate $SCRIPT_DIR/../Builds/LinuxMakefile/Richter.so \
           --strictness-level 10 \
           --skip-gui-tests \
           --disabled-tests $SCRIPT_DIR/disabled-tests.txt
