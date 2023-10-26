/*
  ==============================================================================

    ButtonFactory.cpp
    Created: 14 Oct 2023 11:51:23am
    Author:  mert.kabukcuoglu

  ==============================================================================
*/

#include "ButtonFactory.h"

namespace juce{


CustomButtonFactory::footSwitchButton::footSwitchButton()
{
    setImages(true, true, true,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite,
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
        juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but ˆust add mouselistener
        0.0);
}

void CustomButtonFactory::footSwitchButton::mouseDown(const MouseEvent& event)
{
    isDown = true;
    sendChangeMessage();
    redraw();
}
void CustomButtonFactory::footSwitchButton::mouseUp(const MouseEvent& event)
{
    isDown = false;
    redraw();
}


void CustomButtonFactory::footSwitchButton::redraw()
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

CustomButtonFactory::LED::LED()
{
    setImages(true, true, true,
              juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
              juce::Image(), 1.0, juce::Colours::transparentWhite,
              juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
              0.0);
    
}

void CustomButtonFactory::LED::redraw()
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

void CustomButtonFactory::LED::changeListenerCallback(ChangeBroadcaster * b)
{
    redraw();
}


CustomButtonFactory::toggleSwitchButton::toggleSwitchButton()
{
    setImages(true, true, true,
        juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
        juce::Image(), 1.0, juce::Colours::transparentWhite,
        juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
        0.0);
}

void CustomButtonFactory::toggleSwitchButton::clicked()
{
    isOn = !isOn;
    sendChangeMessage();
    redraw();
}

void CustomButtonFactory::toggleSwitchButton::redraw()
{
    if (isOn)
    {

            setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);

    }
    else
    {
            setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);

    }
    repaint();
}

CustomButtonFactory::dynamicSVGButton::dynamicSVGButton(const String& buttonName = String(), ButtonStyle buttonStyle = ImageFitted)
    :DrawableButton(buttonName, buttonStyle)
{
    if (const auto svg = XmlDocument::parse(BinaryData::metronome_neutral_svg))
    {
        const auto drawable = Drawable::createFromSVG(*svg);
        auto drawableArgument = drawable.get();
        setImages(drawableArgument,
            drawableArgument,
            drawableArgument,
            drawableArgument,
            drawableArgument,
            drawableArgument,
            drawableArgument,
            drawableArgument);
    }
    else
        jassert(svg != nullptr);
}

void CustomButtonFactory::dynamicSVGButton::clicked()
{
    DBG("clicked");
    isOn = !isOn;
    if (isOn)
        startTimer(500);

    else
    {
        stopTimer();
        if (const auto svg = XmlDocument::parse(BinaryData::metronome_neutral_svg))
        {
            const auto drawable = Drawable::createFromSVG(*svg);
            auto drawableArgument = drawable.get();
            setImages(drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument);
        }
        else
            jassert(svg != nullptr);
    }
}
void CustomButtonFactory::dynamicSVGButton::animate()
{
    static bool isLeft{ true };

    if (isLeft)
    {
        if (const auto svg = XmlDocument::parse(BinaryData::metronome_left_svg))
        {
            const auto drawable = Drawable::createFromSVG(*svg);
            auto drawableArgument = drawable.get();
            setImages(drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument);
        }
        else
            jassert(svg != nullptr);

        repaint();
    }
    else
    {
        if (const auto svg = XmlDocument::parse(BinaryData::metronome_right_svg))
        {
            const auto drawable = Drawable::createFromSVG(*svg);
            auto drawableArgument = drawable.get();
            setImages(drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument,
                drawableArgument);
        }
        else
            jassert(svg != nullptr);

        repaint();
    }

    isLeft = !isLeft;

}

void CustomButtonFactory::dynamicSVGButton::timerCallback() 
{
    animate();
    
}

}
