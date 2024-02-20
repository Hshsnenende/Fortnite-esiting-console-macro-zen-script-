define Input_Interval = 10; // Input interval set to 10ms for faster response
int EDIT_BUTTON = PS4_R3;
int SELECT_BUTTON = PS4_L3;
int CONFIRM_BUTTON = PS4_R2;
int RESET_BUTTON = PS4_R3;

main {
    // Building and Editing Controls
    if(get_val(PS4_RIGHT)) {
        // Automated edit selection loop
        combo_run(EDIT_LOOP);
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
    int INSTA_BUILD = 0;
    int EDIT_STATE = 0;

    do {
        // Edit
        set_val(EDIT_BUTTON, 50); // Slight hold for EDIT_BUTTON
        wait(370); // Hold for 370ms
        set_val(EDIT_BUTTON, 0); // Release EDIT_BUTTON

        // Select
        wait(10); // Delay for smoother execution
        set_val(SELECT_BUTTON, 100); // SELECT_BUTTON
        wait(10); // Reduced delay for faster response

        // Confirm
        wait(10); // Delay for smoother execution
        set_val(CONFIRM_BUTTON, 100); // CONFIRM_BUTTON
        wait(15); // Reduced delay for faster response

        // Select again
        wait(10); // Delay for smoother execution
        set_val(SELECT_BUTTON, 100); // SELECT_BUTTON
        wait(20); // Reduced delay for faster response

        // Confirm again
        wait(10); // Delay for smoother execution
        set_val(CONFIRM_BUTTON, 100); // CONFIRM_BUTTON
        wait(15); // Reduced delay for faster response

        // Loop select and confirm with insta build until right arrow is released
        while (get_val(PS4_RIGHT)) {
            set_val(SELECT_BUTTON, 100); // SELECT_BUTTON
            wait(10); // Reduced delay for faster response

            set_val(CONFIRM_BUTTON, 100); // CONFIRM_BUTTON
            wait(15); // Reduced delay for faster response

            // Insta build action
            INSTA_BUILD = !INSTA_BUILD; // Toggle insta build state
            set_val(BUILD_BUTTON, INSTA_BUILD * 100); // Press BUILD_BUTTON
            wait(10); // Delay for smoother execution
            set_val(BUILD_BUTTON, 0); // Release BUILD_BUTTON
        }
    } while (get_val(PS4_RIGHT)); // Loop while right arrow is pressed
}

combo INSTANT_FLOOR_BUILD {
    set_val(PS4_R1, 100);
    wait(10); // Reduced delay for faster response
    set_val(PS4_R1, 0);
}

combo INSTANT_WALL_BUILD {
    set_val(PS4_R2, 100);
    wait(10); // Reduced delay for faster response
    set_val(PS4_R2, 0);
}

combo INSTANT_RAMP_BUILD {
    set_val(PS4_L2, 100);
    wait(10); // Reduced delay for faster response
    set_val(PS4_L2, 0);
}

combo INSTANT_CONE_BUILD {
    set_val(PS4_DOWN, 100);
    wait(10); // Reduced delay for faster response
    set_val(PS4_DOWN, 0);
}