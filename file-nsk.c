define Input_Interval = 25; // Input interval for new gen consoles

init {
    // Define the edit button for Cronus Zen (PS4 Controller)
    int EDIT_BUTTON = PS4_TOUCH; // Edit button for initial edit action
}

main {
    if(get_val(PS4_RIGHT)) {
        // Automated edit selection loop
        combo_run(EDIT_LOOP);
    } else {
        combo_stop(EDIT_LOOP);
    }
    
    // Instant Building for Structures
    if(event_press(PS4_R1)) {
        combo_run(INSTANT_FLOOR_BUILD);
    }

    if(event_press(PS4_R2)) {
        combo_run(INSTANT_WALL_BUILD);
    }

    if(event_press(PS4_L2)) {
        combo_run(INSTANT_RAMP_BUILD);
    }

    if(event_press(PS4_DOWN)) {
        combo_run(INSTANT_CONE_BUILD);
    }
}

combo EDIT_LOOP {
    // Select the edit quickly
    set_val(EDIT_BUTTON, 100); // Press the edit button
    wait(10); // Minimum delay for edit selection

    // Confirm the edit quickly
    // (Simulated confirmation action - manual confirmation may be required)
    wait(10); // Minimum delay for confirmation

    // Reset the edit quickly
    set_val(EDIT_BUTTON, 0); // Release the edit button
    wait(10); // Minimum delay before next edit selection

    wait(10); // Minimum delay before repeating the loop
}

combo INSTANT_FLOOR_BUILD {
    set_val(PS4_R1, 100); // Press the button for building floor
    wait(25); // Delay for building placement
    set_val(PS4_R1, 0); // Release the building button
}

combo INSTANT_WALL_BUILD {
    set_val(PS4_R2, 100); // Press the button for building wall
    wait(25); // Delay for building placement
    set_val(PS4_R2, 0); // Release the building button
}

combo INSTANT_RAMP_BUILD {
    set_val(PS4_L2, 100); // Press the button for building ramp
    wait(25); // Delay for building placement
    set_val(PS4_L2, 0); // Release the building button
}

combo INSTANT_CONE_BUILD {
    set_val(PS4_DOWN, 100); // Press the button for building cone
    wait(25); // Delay for building placement
    set_val(PS4_DOWN, 0); // Release the building button
}