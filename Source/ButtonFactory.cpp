/*
  ==============================================================================

    ButtonFactory.cpp
    Created: 14 Oct 2023 11:51:23am
    Author:  mert.kabukcuoglu

  ==============================================================================
*/

#include "ButtonFactory.h"

namespace juce{


CustomButtonFactory::testButton::testButton(ChangeListener& l)
{
    setImages(true, true, true,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
        0.0);
    addChangeListener(&l);
}

void CustomButtonFactory::testButton::mouseDown(const MouseEvent& event)
{
    isDown = true;
    sendChangeMessage();
    redraw();
}
void CustomButtonFactory::testButton::mouseUp(const MouseEvent& event)
{
    isDown = false;
    redraw();
}


void CustomButtonFactory::testButton::redraw()
{
    if(isDown)
    {
        setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_down_png, BinaryData::footswitch_down_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_down_png, BinaryData::footswitch_down_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
            juce::ImageCache::getFromMemory(BinaryData::footswitch_down_png, BinaryData::footswitch_down_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
            0.0);
    }
    else
    {
        setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
            juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
            0.0);
    }
    repaint();
}

CustomButtonFactory::testLED::testLED()
{
    setImages(true, true, true,
              juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
              juce::Image(), 1.0, juce::Colours::transparentWhite,
              juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
              0.0);
    
}

void CustomButtonFactory::testLED::redraw()
{
    isOn = !isOn;
    
    if(isOn)
    {
        setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
            juce::ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
            0.0);
    }
    else
    {
        setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
            juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
            0.0);
    }
    repaint();
}

void CustomButtonFactory::testLED::changeListenerCallback(ChangeBroadcaster * b)
{
    redraw();
}

}
