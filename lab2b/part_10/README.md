# PROTOBOARD

- The following demonstration video shows the sequencer integrated along with the initial proposal board (that was used to play the game - guessing game).




https://user-images.githubusercontent.com/114244849/202835152-5bc9642c-2eee-420b-940f-033fae3eded3.mp4


- Here, the guessing game proposed in the beginning of the lab was used, along with the PIO based sequencer that we created in the duration of the lab.
- There are various modes which can be activated using macros.
- The first macro, was r, which was used to record a sequence of BOOT pin presses.
- Secondly, p was used to play the recorded BOOT pin presses.
- Finally, the g macro was used to enter the game mode which activated the guessing game, where the user is asked to enter a number that would be considered as a seed to generate a random number.
- Based on the generated random number whose function can be found here.
- Then, the user is asked to enter a guess and based on whether the value entered is higher or lower than the random number generated, the user is prompted by printing Think higher!! or Think Lower!!.
- Until the user guesses the correct answer the RED LED blinks at each guess, once the user guesses the right answer the BLUE LED blinks, and the game mode is exited.
- The program then brings the user back to the beginning and waits for the user to enter a macro.
