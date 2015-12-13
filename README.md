# TouchScreenDebouncingDemo
A short program that demonstrates the noisy character of touchscreens and how to filter it out.

On an enigma machine, a key press will move the encoding wheels first, then apply electricity to the entry rotor and the encoded letter will light up in the lamp field. The lamp will be lit for as long as the key is pressed, once the key is released, the lamp will turn off and further key presses will move the rotors again.

When simulating this with a touchscreen, it is vital to ensure that one filters out false release events so that the rotors are not moved unnecessarily.

The code below shows how the touch screen reports no touch detected while a finger is being dragged across the screen.

The phantom touch logic was added after noticing that earlier versions of the machine were changing settings by themselves. Even though the manufacturer uses a minimum pressure check in the code, I noticed it was necessary to add a maximum value to prevent those phantom clicks. The threshold was determined by printing pressure readings greater than 0.

A short drag across the screen results in this output, of particular notice is the “no touch detected” line in between the “screen touch at” lines, even though the finger was never lifted during the dragging motion. Even pressing down firmly on one spot results in the occasional “no touch detected” line. Notice the phantom touch while the screen was idle.

initial screen touch at 164 156 <br>
screen touch at 164 154 <br>
no touch detected <br>
no touch detected <br>
screen touch at 159 143 <br>
screen touch at 147 138 <br>
screen touch at 128 139 <br>
screen touch at 106 149 <br>
no touch detected <br>
screen touch at 77 181 <br>
screen touch at 76 198 <br>
screen touch at 83 207 <br>
screen touch at 97 207 <br>
screen touch at 120 190 <br>
screen touch at 147 161 <br>
screen touch at 160 133 <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
no touch detected <br>
release registered <br>
Phantom touch at 208 309 <br>
