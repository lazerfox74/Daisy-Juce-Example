#include <math.h>
//idk if that cmath is neccecary

class Wavetable 
{
    public:

        //default constructor needed for array;
        Wavetable(int sRate,int bSize,float freq);
        Wavetable(); //default constructor
        ~Wavetable();
        //   float GetSample(float index);

        void setTable(char table);
        float play(float frequency, float morph);
        void setFreq(float freq);

        void setMorph(float morph);


        //decide if should be static or not

        //define might not be the best
        static const size_t tableSize = 1024;
        static const size_t tableRez = 128;

        float sampleRate;
        char blockSize;


        float *tablePtr;

        float lerpF(float position,float morph);

        //to be called once each cycle
        float updateTable();

        float tableMorph;




    private:

        static float table0[tableSize];
        static float table1[tableSize];


        float bufferInc;
        float bufferPos;

        float freq;

        


        // void lerp



        //idk if sample rate is in floats this might need to be changed
        //also idk about static but should be calm as sample rate not gunna change and willl b the same;


};
