#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "daisysp.h"

#include "Wavetable.h"



//==============================================================================
class AudioPluginAudioProcessor : public juce::AudioProcessor
{
public:
	//==============================================================================
	AudioPluginAudioProcessor();
	~AudioPluginAudioProcessor() override;

	//==============================================================================
	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

	void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
	using AudioProcessor::processBlock;

	//==============================================================================
	juce::AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	//==============================================================================
	const juce::String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	//==============================================================================
	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const juce::String getProgramName(int index) override;
	void changeProgramName(int index, const juce::String& newName) override;

	//==============================================================================
	void getStateInformation(juce::MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	float noteVal, noteMidi,freq,tableMorph, morph;
	float ratio, index;

	Wavetable myTable = Wavetable(48000,4,100);


private:
	daisysp::Fm2 osc;
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessor)
};
