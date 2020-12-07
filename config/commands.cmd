#define ROTATE_SPEED     30
/*
 *  Przykładowy zestaw poleceń
 */
  Set   Ob_A 2 0 0    // Polozenie obiektu A 
  Set   Ob_B 10 10 0   // Polozenie obiektu B
  Set   Ob_C -10 -10 0   // Polozenie obiektu C
  Rotate Ob_A ROTATE_SPEED 30
  Move  Ob_A 10 10
  Pause 1000 /* Zawieszenie na 1 sek. */
  Rotate Ob_B ROTATE_SPEED 60 /* Rotate i Move wykonywane razem */
  Move  Ob_B 10 20            /* powoduja jazde po luku         */
  Rotate Ob_C ROTATE_SPEED 50
  Move  Ob_C 10 10
  Rotate Ob_A ROTATE_SPEED 90
  Move  Ob_A 10 30
