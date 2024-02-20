combo EDIT_LOOP {
    int EDIT_BUTTON = PS4_R3; // Define your EDIT_BUTTON
    int SELECT_BUTTON = PS4_L3; // Define your SELECT_BUTTON
    int CONFIRM_BUTTON = PS4_R2; // Define your CONFIRM_BUTTON
    int PS4_RIGHT = PS4_RT; // Define your PS4_RIGHT (Right Trigger)

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

    } while (get_val(PS4_RIGHT)); // Loop while right trigger is pressed
}