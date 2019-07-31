/*
 * References:
 *   - http://www.phy.mtu.edu/~suits/notefreqs.html
 *   - https://en.wikipedia.org/wiki/Scientific_pitch_notation#Table_of_note_frequencies
 *   - http://soundcalledmusic.com/scientific-pitch-notation/
 */
enum Note_Freq {
  NOTE_B0  = 31,
  NOTE_C1  = 33,
  NOTE_CS1 = 35,
  NOTE_D1  = 37,
  NOTE_DS1 = 39,
  NOTE_E1  = 41,
  NOTE_F1  = 44,
  NOTE_FS1 = 46,
  NOTE_G1  = 49,
  NOTE_GS1 = 52,
  NOTE_A1  = 55,
  NOTE_AS1 = 58,
  NOTE_B1  = 62,
  NOTE_C2  = 65,
  NOTE_CS2 = 69,
  NOTE_D2  = 73,
  NOTE_DS2 = 78,
  NOTE_E2  = 82,
  NOTE_F2  = 87,
  NOTE_FS2 = 93,
  NOTE_G2  = 98,
  NOTE_GS2 = 104,
  NOTE_A2  = 110,
  NOTE_AS2 = 117,
  NOTE_B2  = 123,
  NOTE_C3  = 131,
  NOTE_CS3 = 139,
  NOTE_D3  = 147,
  NOTE_DS3 = 156,
  NOTE_E3  = 165,
  NOTE_F3  = 175,
  NOTE_FS3 = 185,
  NOTE_G3  = 196,
  NOTE_GS3 = 208,
  NOTE_A3  = 220,
  NOTE_AS3 = 233,
  NOTE_B3  = 247,
  NOTE_C4  = 262,
  NOTE_CS4 = 277,
  NOTE_D4  = 294,
  NOTE_DS4 = 311,
  NOTE_E4  = 330,
  NOTE_F4  = 349,
  NOTE_FS4 = 370,
  NOTE_G4  = 392,
  NOTE_GS4 = 415,
  NOTE_A4  = 440,
  NOTE_AS4 = 466,
  NOTE_B4  = 494,
  NOTE_C5  = 523,
  NOTE_CS5 = 554,
  NOTE_D5  = 587,
  NOTE_DS5 = 622,
  NOTE_E5  = 659,
  NOTE_F5  = 698,
  NOTE_FS5 = 740,
  NOTE_G5  = 784,
  NOTE_GS5 = 831,
  NOTE_A5  = 880,
  NOTE_AS5 = 932,
  NOTE_B5  = 988,
  NOTE_C6  = 1047,
  NOTE_CS6 = 1109,
  NOTE_D6  = 1175,
  NOTE_DS6 = 1245,
  NOTE_E6  = 1319,
  NOTE_F6  = 1397,
  NOTE_FS6 = 1480,
  NOTE_G6  = 1568,
  NOTE_GS6 = 1661,
  NOTE_A6  = 1760,
  NOTE_AS6 = 1865,
  NOTE_B6  = 1976,
  NOTE_C7  = 2093,
  NOTE_CS7 = 2217,
  NOTE_D7  = 2349,
  NOTE_DS7 = 2489,
  NOTE_E7  = 2637,
  NOTE_F7  = 2794,
  NOTE_FS7 = 2960,
  NOTE_G7  = 3136,
  NOTE_GS7 = 3322,
  NOTE_A7  = 3520,
  NOTE_AS7 = 3729,
  NOTE_B7  = 3951,
  NOTE_C8  = 4186,
  NOTE_CS8 = 4435,
  NOTE_D8  = 4699,
  NOTE_DS8 = 4978,
};


#define __ASSERT_USE_STDERR
#include <assert.h> /* defines assert(); uses __assert() defined below */
//#include "notes.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

enum {
  PIN_BUZZER = 3,
  //PIN_LED    = 13,
};

enum Note_Type {
  NT_NOTE,
  NT_REST,
  NT_MM /**< metronome mark */
};

/** Default metronome mark, crotchets per minute. */
enum { DEFAULT_MM = 120 };

/** The duration of the whole note, miliseconds. */
static unsigned int whole_note;

struct Note {
  enum Note_Type n_type;
  /** See enum Note_Freq for values. */
  unsigned int n_frequency;
  /**
   * Inverted note value.
   *
   * 1 - whole (semibreve),
   * 2 - half (minim),
   * 4 - quarter (crotchet),
   * 8 - eighth (quaver),
   * etc.
   *
   * If .n_type == NT_MM, then .n_value specifies the number
   * of crotchets per minute.
   */
  unsigned int n_value;
  /** Whether to "join" this note with the next one. */
  bool n_slur;
};

static bool note_invariant(const struct Note *note)
{
  return note != NULL &&
    (note->n_type >= NT_NOTE && note->n_type <= NT_MM) &&
    note->n_value != 0 &&
    /* only NOTEs can have .n_slur set */
    (!note->n_slur || note->n_type == NT_NOTE) &&
    /* only NOTEs can have non-zero .n_frequency */
    (note->n_frequency == 0 || note->n_type == NT_NOTE);
}

#define n(pitch, value)  { NT_NOTE, NOTE_ ## pitch, (value), false }
#define ns(pitch, value) { NT_NOTE, NOTE_ ## pitch, (value), true }
#define r(value)         { NT_REST, 0, (value), false }
#define mm(value)        { NT_MM, 0, (value), false }

/* https://en.wikipedia.org/wiki/Note_value */
static unsigned int dot(unsigned int inverted_value)
{
  /* Add 1 to compensate for integer division. */
  return (inverted_value + 1) * 2 / 3;
}

/* https://youtu.be/P5L6Qgmcjfw */
static struct Note sherlock[] = {
  mm(200),
#define XXX_LEFTY 0
#if XXX_LEFTY
  n(C3,4), n(G3,4), n(G2,4), n(G3,4),
  n(C3,4), n(G3,4), n(G2,4), n(G3,4),
#else
  r(1),
  r(1),
#endif
  n(C4,4), n(G4,2), n(G4,4),
  n(FS4,8), n(G4,8), n(GS4,2), n(G4,4),
  n(F4,4), ns(C5,dot(2)),
  n(C5,1),

  n(F4,4), n(C5,2), n(C5,4),
  n(B4,8), n(C5,8), n(D5,2), n(C5,4),
  ns(DS5,1),
  n(DS5,1),
  n(G5,4), n(C5,2), n(C5,4),
  n(D5,4), n(DS5,4), n(D5,4), n(C5,4),

  n(F5,4), n(C5,4), r(2),
  r(2), r(4), n(C5,8), n(D5,8),
  n(DS5,4), n(DS5,8), n(F5,8), n(D5,4), n(D5,8), n(DS5,8),

  n(C5,4), n(C5,8), n(D5,8), n(B4,4), n(GS4,8), n(G4,8),
  n(C5,1),
};

//#if 0 /* XXX -------------------------------------------------------- */
/* http://www.8notes.com/scores/1110.asp */
static struct Note happy_birthday[] = {
  n(C4,dot(8)), n(C4,16),
  n(D4,4), n(C4,4), n(F4,4),
  n(E4,2), n(C4,dot(8)), n(C4,16),
  n(D4,4), n(C4,4), n(G4,4),
  n(F4,2), n(C4,dot(8)), n(C4,16),

  n(C5,4), n(A4,4), n(F4,4),
  n(E4,4), n(D4,4), n(AS4,dot(8)), n(AS4,16),
  n(A4,4), n(F4,4), n(G4,4),
  n(F4,dot(2)),
};

/* https://youtu.be/xAMsLDQi2b0 */
static struct Note monkey_island_intro[] = {
  mm(120),
  ns(E4,16), ns(B4,16), ns(E5,16), ns(FS5,16), ns(FS5,dot(2)), n(FS5,1),
  ns(E6,16), ns(B5,16), ns(G5,16), ns(FS5,16), n(FS5,2), n(D5,4),
  n(E5,4), n(FS5,4), n(D5,4), n(E5,4),
  n(B4,2), ns(G3,4), ns(A3,4),

  ns(B3,1),
  ns(D4,2), ns(CS4,2),
  ns(D4,2), ns(E4,2),
  ns(F4,4), ns(G4,4), ns(A4,2),
  ns(B4,2), n(D5,2),
  mm(88),
  n(E3,16), ns(E4,16), ns(G4,16), n(E4,16), ns(B4,16), ns(G4,16), n(E4,8), n(D3,16), ns(D4,16), ns(F4,16), n(D4,16),
  n(E3,16), ns(E4,16), ns(G4,16), n(E4,16), ns(B4,16), ns(G4,16), n(E4,8), n(D3,16), ns(D4,16), ns(F4,16), n(D4,16), n(E3,16), ns(E4,16), ns(G4,16), n(E4,16),
  n(E5,8), ns(E5,16), ns(G5,16), ns(FS5,16), n(E5,16), n(D5,8), n(E5,4), r(4), n(D5,8),
  ns(D5,16), ns(C5,16), ns(B4,16), ns(D5,16), n(C5,dot(8)), n(C5,dot(8)), n(B4,4), r(4), n(E5,dot(8)),

  n(E5,dot(8)), ns(G5,16), ns(FS5,16), ns(E5,16), n(D5,8), ns(E5,4), n(E5,dot(8)), n(FS5,16),
  n(G5,dot(8)), n(G5,dot(8)), n(A5,4), n(FS5,dot(8)), ns(G5,16), ns(FS5,16), ns(E5,16), ns(D5,16), ns(FS5,16),
  n(G5,dot(8)), n(G5,dot(8)), n(FS5,4), n(E5,dot(8)), ns(G5,16), ns(FS5,16), ns(E5,16), ns(D5,16), ns(FS5,16),

  n(G5,dot(8)), n(G5,dot(8)), n(FS5,4), n(E5,dot(8)), ns(G5,16), ns(FS5,16), ns(E5,16), ns(D5,8),
  n(E5,dot(8)), n(E5,dot(8)), n(E5,dot(4)), n(E5,8), ns(D5,16), ns(C5,16), ns(B4,16), ns(D5,16), n(C5,dot(8)), n(C5,dot(8)),
  n(B4,4), r(4), r(4),
  r(4), r(4), n(B4,8), n(D5,8),

  ns(C6,8), n(G5,8), n(G5,4), ns(C6,16), ns(B5,16), ns(A5,16), ns(C6,16),
  ns(B5,8), n(G5,8), n(G5,dot(4)), n(B4,4), n(G5,8),
  ns(A5,8), n(D5,8), n(D5,dot(8)), ns(A5,16), ns(B5,16), ns(A5,16), ns(G5,16), n(A5,16),

  ns(B5,8), n(G5,dot(8)), ns(G5,8), n(E5,dot(8)), n(E5,4), n(F4,8), n(G4,8),
  ns(A4,16), ns(F4,16), ns(C5,16), ns(A4,16), ns(F5,16), ns(C5,16), ns(A5,16), ns(F5,16), ns(C5,16), ns(A4,16), ns(F5,16), ns(C5,16), ns(A5,16), ns(F5,16), ns(C6,16), n(F6,16),
  ns(G5,8), n(E5,dot(8)), n(E5,dot(8)), n(G5,16), n(FS5,dot(8)), n(G5,dot(8)), n(FS5,16), n(G5,16), n(E5,16), n(G5,16),

  r(16), ns(C4,16), ns(G4,16), ns(DS4,16), ns(C5,16), ns(G4,16), ns(C5,16), ns(DS5,16), r(16), ns(G4,16), ns(E5,16), ns(C5,16), ns(G5,16), ns(E5,16), ns(G5,16), n(C6,16),
  r(8), n(FS5,dot(8)), n(FS5,dot(8)), n(FS5,16), n(E5,dot(8)), n(FS5,dot(8)), n(E5,16), n(FS5,16), n(D5,8),
  n(E5,dot(8)), ns(E5,16), ns(G5,16), ns(FS5,16), ns(E5,16), n(D5,dot(8)), n(E5,4), r(8), n(D5,8),
  /* XXX WIP */
};
//#endif /* XXX ------------------------------------------------------- */

#undef mm
#undef r
#undef s
#undef n

static void _play(const struct Note *score, size_t score_len, const char *name)
{
  const struct Note *note;
  unsigned int duration;

  whole_note = 240000 / DEFAULT_MM;
  if (name != NULL)
    Serial.println(name);
  for (size_t i = 0; i < score_len; ++i) {
    note = &score[i];
    assert(note_invariant(note));
    if (note->n_type == NT_MM) {
      /* MM * t/4 = 60s ==> t = 240s / MM */
      whole_note = 240000 / note->n_value;
      continue;
    }
    duration = whole_note / note->n_value;
    if (note->n_type == NT_REST) {
      delay(duration);
      continue;
    }
    assert(note->n_type == NT_NOTE);
    if (note->n_slur) {
      buzz(note->n_frequency, duration);
    } else {
      buzz(note->n_frequency, 0.7 * duration);
      delay(0.3 * duration); /* pause between notes */
    }
  }
}
#define play(score) _play(score, ARRAY_SIZE(score), #score)

/*
 * `frequency' is the number of cycles per second.
 * `duration' is measured in miliseconds.
 */
static void buzz(long frequency, long duration)
{
  assert(frequency != 0);
//  digitalWrite(PIN_LED, HIGH);
  /*
   * Delay between transitions =
   * 1 second's worth of microseconds / frequency / 2,
   * where 2 is number of phases (HIGH and LOW) per cycle.
   */
  long delay = 1000000 / frequency / 2;
  long ncycles = frequency * duration / 1000;
  for (long i = 0; i < ncycles; i++) {
    digitalWrite(PIN_BUZZER, HIGH);
    delayMicroseconds(delay);
    digitalWrite(PIN_BUZZER, LOW);
    delayMicroseconds(delay);
  }
//  digitalWrite(PIN_LED, LOW);
}

/** Handle diagnostic informations given by assertion and abort program. */
void __assert(const char *__func, const char *__file, int __lineno,
        const char *__sexp)
{
  Serial.print(__file);
  Serial.print(':');
  Serial.print(__lineno, DEC);
  Serial.print(" (");
  Serial.print(__func);
  Serial.print("): ");
  Serial.println(__sexp);
  Serial.flush();
  abort();
}

void setup(void)
{
  pinMode(PIN_BUZZER, OUTPUT);
//  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  /* play(mario_overworld); */
  /* play(mario_underworld); */
  /* play(mario_death); */
 // play(sherlock);
   play(happy_birthday); 
 //  play(monkey_island_intro); 
}
