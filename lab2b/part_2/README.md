### REPL

This part creates a REPL that lets us read and write from and to RP2040 registers from a console. It also covers reading/ writing using or atomic bit- setting aliases which does a bitwise operation between each of the corresponding bits.


## IMAGE REPRESENTATION 

![lab2b_part2_repl](https://user-images.githubusercontent.com/114244849/200732550-cbe3c9ea-ea8f-437b-8c63-37ef79bc70c3.JPG)

<br>

1) The ```QTPY_GPIO_CTRL_REG``` macro is defined with the register address of ```GPIO0``` . This address is ```IO_BANK0_BASE + 0x004``` , since this is what the boot button is connected to. 

2) In the main function , the ``` register_read()``` function is used to read the current value stored in the register at the address ```QTPY_GPIO_CTRL_REG```. 

3) The user is asked for a value to overwrite the current value stored in the register. This value is stored in the variable ```reg_updated_value```. This value is then written to the register using the ```register_write()``` function.
