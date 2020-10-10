[![CI Main](https://github.com/jd-13/Richter-Tremolo/workflows/CI%20Main/badge.svg)](https://github.com/jd-13/Richter-Tremolo/actions?query=workflow%3A%22CI+Main%22)
![](https://img.shields.io/badge/C%2B%2B-17-informational)
![](https://img.shields.io/badge/license-GPLv3-informational)

# Richter-Tremolo
Richter is a VST and Audio Unit tremolo plugin built using JUCE, featuring four tempo sync-able LFOs, two of which modulate the signal directly, whilst the other two modulate the previous two LFOs

For more details and a free download of the compiled plugin: https://www.whiteelephantaudio.com/plugins/richter  

![](https://whiteelephantaudio.com/images/thumbs/originals/richterFull.png)

## Built using:  

JUCE: https://www.juce.com/  

WECore: https://github.com/jd-13/WE-Core  

VST SDK: https://www.steinberg.net/en/company/developers.html  

## Build Instructions

Like other JUCE applications, Richter is built using the Projucer. There are however 2 steps needed
before it will build successfully:

1. Update the header search paths to point to the location of WECore on your machine
2. Download the font [Montserrat](https://fonts.google.com/specimen/Montserrat) and place the
regular ttf file in Source/Graphics
