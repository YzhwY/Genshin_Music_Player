#include <iostream>
#include <Windows.h>
#include <map>
#include <thread>
#include <unordered_map>
#include <vector>
#include <queue>
#include "MusicNote.h"

#pragma comment(lib, "winmm.lib")

using namespace std;

HMIDIOUT handle;

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
    //HMIDIOUT handle;
    midiOutOpen(&handle, 0, 0, 0, CALLBACK_NULL);

    int volume = 0x7F; // 音量（0-127）

    int midiValue = noteToMidi[noteValue];

    int midiMessage = (volume << 16) + (midiValue << 8) + 0x90; // MIDI Note On 消息
    midiOutClose(handle);
    midiOutShortMsg(handle, midiMessage);
    

    Sleep(duration);

    midiOutShortMsg(handle, (volume << 16) + (midiValue << 8) + 0x80);

    //midiOutClose(handle);
}

void play_sound_chord(queue<int>& chordQueue, queue<int>& durationQueue) {
    while (!chordQueue.empty()) {
        int noteValue = chordQueue.front();
        int noteDuration = durationQueue.front();
        chordQueue.pop();
        durationQueue.pop();
        play_sound(noteValue, noteDuration);
    }
}



unordered_map<char, int> charToIntMap = {
    {'Z', 1}, {'X', 2}, {'C', 3}, {'V', 4}, {'B', 5}, {'N', 6}, {'M', 7},
    {'A', 8}, {'S', 9}, {'D', 10}, {'F', 11}, {'G', 12}, {'H', 13}, {'J', 14},
    {'Q', 15}, {'W', 16}, {'E', 17}, {'R', 18}, {'T', 19}, {'Y', 20}, {'U', 21}
};

int stringToInt(const string& input) {
    int result = 0;

    for (char c : input) {
        auto it = charToIntMap.find(c);
        if (it != charToIntMap.end()) {
            result = result * 100 + it->second;
        }
        else {
            cout << "ERR" << endl;
            return 0;
        }
    }

    return result;
}

int main() {
    string a = "DDFGGFDSAASDDSS";
    int testtime[100] = { 500,500,500,500,500,500,500,500,500,500,500,500,750,250,1000 };
    queue<int> time;
    queue<string> b;
    for (int i = 0; i < 14; i++) {
        time.push(testtime[i]);
    }
    for (char c : a) {
        string letter(1, c); // 将字符转换为字符串
        b.push(letter);
    }
    cout << "1";
    while (!b.empty()) {
        //midiOutClose(handle);
        cout << b.front() << " ";
        cout << time.front() << endl;
        play_sound(stringToInt(b.front()), time.front());
        b.pop();
        time.pop();
    }
    return 0;
}
