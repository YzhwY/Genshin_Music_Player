#include <iostream>
#include <Windows.h>
#include <map>
#include <thread>
#include<vector>

#pragma comment(lib, "winmm.lib")

using namespace std;

//显而易见，下面这个map是ChatGPT编写的
map<int, int> noteToMidi = {
    {1, 46}, //do
    {2, 48}, //re
    {3, 50}, //mi
    {4, 52}, //fa
    {5, 54}, //so
    {6, 56}, //la
    {7, 58},//ti
    {8, 60},//do
    {9, 62},//re
    {10, 64},//mi
    {11, 66},//fa
    {12, 68},//so
    {13, 70},//la
    {14, 72},//ti
    {15, 74},//do
    {16, 76},//re
    {17, 78},//mi
    {18, 80},//fa
    {19, 82},//so
    {20, 84},//la
    {21, 86},//ti
    {22, 88},//do
};

//显而易见，下面这个函数是ChatGPT编写的
void play_sound(int noteValue, int duration) {
    HMIDIOUT handle;
    midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);

    int volume = 0x7F; // 音量（0-127）

    int midiValue = noteToMidi[noteValue];
    int midiMessage = (volume << 16) + (midiValue << 8) + 0x90; // MIDI Note On 消息

    midiOutShortMsg(handle, midiMessage);

    Sleep(duration);

    midiOutShortMsg(handle, (volume << 16) + (midiValue << 8) + 0x80);

    midiOutClose(handle);
}

void p(string name,int time) {
    if (name == "A") {
        play_sound(8, time);
    }
    if (name == "S") {
        play_sound(9, time);
    }
    if (name == "D") {
        play_sound(10, time);
    }
    if (name == "F") {
        play_sound(11, time);
    }
    if (name == "G") {
        play_sound(12, time);
    }
    if (name == "H") {
        play_sound(13, time);
    }
    if (name == "J") {
        play_sound(14, time);
    }
}

int main() {
    p("A", 500);
    p("S", 500);
    p("D", 500);
    return 0;
}

