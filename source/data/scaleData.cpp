#include "scaleData.h"

const QString allNotes[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "H"};
const QString allClassicScales[9] = {"Major", "Natural Minor", "Harmonic Minor", "Melodic Minor", "Dorian", "Phrygian", "Lydian", "Mixolydian", "Locrian"};

chordsType templateChordTypes[9][7] = {
        {major, minor, minor, major, major, minor, diminished},
        {minor, diminished, major, minor, minor, major, major},
        {minor, diminished, major, minor, major, major, diminished},
        {minor, minor, increased, major, major, diminished, diminished},
        {minor, minor, major, major, minor, diminished, major},
        {minor, major, major, minor, diminished, major, minor},
        {major, major, minor, diminished, major, minor, minor},
        {major, minor, diminished, major, minor, minor, major},
        {diminished, minor, major, minor, major, major, minor}
};

int templateDistances[9][7] = {
        {2, 2, 1, 2, 2, 2, 1},
        {2, 1, 2, 2, 1, 2, 2},
        {2, 1, 2, 2, 1, 3, 1},
        {2, 1, 2, 2, 2, 2, 1},
        {2, 1, 2, 2, 2, 1, 2},
        {1, 2, 2, 2, 1, 2, 2},
        {2, 2, 2, 1, 2, 2, 1},
        {2, 2, 1, 2, 2, 1, 2},
        {1, 2, 2, 1, 2, 2, 2}
};
int chordTemplate[4][2] = {
        {4, 3},
        {3, 4},
        {3, 3},
        {4, 4}
};
QString notesMapper[12] = {
        "C" , "D" , "E",
        "F" , "G" , "A",
        "H" , "C#" , "D#",
        "F#" , "G#" , "A#"
};

#define COLOR_TONIKA 0xff87a5
#define COLOR_DOMINANTA 0x4fcee9
#define COLOR_SUBDOMINANTA 0x69ddea
#define COLOR_MEDIANTA 0xfbd4a1
#define COLOR_SUPERTONIKA 0xb6a3dc
#define COLOR_SUBMEDIANTA 0xa1fbc3
#define COLOR_ZMNIEJSZONY 0xeabf69


QColor chordsColors[9][7] = {
        // Major Scale (Skala durowa)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Natural Minor Scale (Skala molowa naturalna)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_DOMINANTA},
        // Harmonic Minor Scale (Skala molowa harmoniczna)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Melodic Minor Scale (Skala molowa melodyczna)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Dorian Scale (Skala dorycka)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Phrygian Scale (Skala frygijska)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Lydian Scale (Skala lidyjska)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Mixolydian Scale (Skala miksolidyjska)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY},
        // Locrian Scale (Skala lokrycka)
        {COLOR_TONIKA, COLOR_SUPERTONIKA, COLOR_MEDIANTA, COLOR_SUBDOMINANTA, COLOR_DOMINANTA, COLOR_SUBMEDIANTA, COLOR_ZMNIEJSZONY}
};


