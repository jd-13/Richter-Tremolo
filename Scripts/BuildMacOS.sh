#!/bin/bash

set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd )"

echo "=== Cloning WE-Core ==="
WECORE_HOME=$SCRIPT_DIR/../WECore
git clone https://github.com/jd-13/WE-Core $WECORE_HOME

cd $WECORE_HOME
echo "=== Using WE-Core $(git log --pretty=format:'%h' -n 1) ==="
cd -

echo "=== Downloading fonts ==="
wget https://github.com/JulietaUla/Montserrat/raw/master/fonts/ttf/Montserrat-Regular.ttf \
     -P $SCRIPT_DIR/../Source/Graphics

echo "=== Downloading JUCE ==="
JUCE_VERSION=7.0.9
wget https://github.com/juce-framework/JUCE/releases/download/$JUCE_VERSION/juce-$JUCE_VERSION-osx.zip \
     -P $SCRIPT_DIR/..
unzip $SCRIPT_DIR/../juce-$JUCE_VERSION-osx.zip

echo "=== Setting module paths ==="
sed -i '' -e 's#../../../../../SDKs/JUCE/modules#JUCE/modules#g' $SCRIPT_DIR/../Richter.jucer

echo "=== Updating include paths ==="
sed -i '' -e 's#../../../WECore/WECore#../../WECore/WECore#g' $SCRIPT_DIR/../Richter.jucer

echo "=== Generating project ==="
$SCRIPT_DIR/../JUCE/Projucer.app/Contents/MacOS/Projucer --resave $SCRIPT_DIR/../Richter.jucer

echo "=== Starting build ==="
cd $SCRIPT_DIR/../Builds/MacOSX
xcodebuild -version
xcodebuild -project Richter.xcodeproj -scheme "Richter - All" -configuration Debug

echo "=== Collecting artefacts ==="
mkdir -p $SCRIPT_DIR/dist
cp -r ~/Library/Audio/Plug-Ins/VST3/Richter.vst3 $SCRIPT_DIR/dist
cp -r ~/Library/Audio/Plug-Ins/Components/Richter.component $SCRIPT_DIR/dist
