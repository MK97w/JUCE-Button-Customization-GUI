#include "MainComponent.h"


    //==============================================================================
    MainComponent::MainComponent()
    {
        setSize(originalWidth, originalHeight);
       
        toggleSwitchButton.setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);
        addAndMakeVisible(toggleSwitchButton);
        toggleSwitchButton.onClick = [this] { toggleSwitchButtonState = !toggleSwitchButtonState ; redraw(); DBG("pressed"); };


        toggleSwitchLed.setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);
        addAndMakeVisible(toggleSwitchLed);


        footSwitchButton.setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::footswitch_up_png, BinaryData::footswitch_up_pngSize), 1.0, juce::Colours::transparentWhite, //this is for overimage
            juce::ImageCache::getFromMemory(BinaryData::footswitch_down_png, BinaryData::footswitch_down_pngSize), 1.0, juce::Colours::transparentWhite, //this is for when buttondown but öust add mouselistener
            0.0);
        addAndMakeVisible(footSwitchButton);
        footSwitchButton.onClick = [this] {footSwitchButtonState = !footSwitchButtonState; redraw(); };


        footSwitchLed.setImages(true, true, true,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
            juce::Image(), 1.0, juce::Colours::transparentWhite,
            juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
            0.0);
        addAndMakeVisible(footSwitchLed);

    }

    MainComponent::~MainComponent()
    {
    }

    //==============================================================================
    void MainComponent::paint(juce::Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

        g.setFont(juce::Font(16.0f));
        g.setColour(juce::Colours::white);
        
    }

    void MainComponent::resized()
    {
        // This is called when the MainComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.

        toggleSwitchButton.setBounds(9, 250, 35, 45);
        toggleSwitchLed.setBounds(40, 100, 35, 45);
        footSwitchButton.setBounds(300, 250, 35, 45);
        footSwitchLed.setBounds(340,100,35,45);
    }


    void MainComponent::redraw()
    {
        if ( toggleSwitchButtonState )
        {

            toggleSwitchButton.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);

            toggleSwitchLed.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::led_red_on_png, BinaryData::led_red_on_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::led_red_on_png, BinaryData::led_red_on_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);
        }
        else
        {
            toggleSwitchButton.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);

            toggleSwitchLed.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::led_red_off_png, BinaryData::led_red_off_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);
        }

        if (footSwitchButtonState)
        {

            footSwitchLed.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);
        }
        else
        {
            footSwitchLed.setImages(true, true, true,
                juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
                juce::Image(), 1.0, juce::Colours::transparentWhite,
                juce::ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, juce::Colours::transparentWhite,
                0.0);
        }

        repaint();
    }