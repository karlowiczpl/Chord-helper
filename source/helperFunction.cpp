#include "Scales.h"

std::vector<QString> Scales::getAllNotes() {
    return note;
}
int Scales::getScaleSize() const
{
    return size;
}

QString Scales::getChordName(int position) {
    return chordNames[position];
}

std::vector<QString> Scales::getChordNotes(int position) {
    return chords[position];
}