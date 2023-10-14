/*
  ==============================================================================

    ButtonFactory.cpp
    Created: 14 Oct 2023 11:51:23am
    Author:  mert.kabukcuoglu

  ==============================================================================
*/

#include "ButtonFactory.h"

namespace juce{

CustomButtonFactory::testButton::testButton()
{
    setImages(true, true, true,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
        0.0);
}

void CustomButtonFactory::testButton::mouseDown(const MouseEvent& event)
{
    DBG("DOWN");
}



}
