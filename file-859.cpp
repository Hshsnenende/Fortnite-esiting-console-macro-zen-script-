combo EDIT_LOOP {
    int INSTA_BUILD = 0;
    int EDIT_BUTTON = PS4_R3;
    int SELECT_BUTTON = PS4_L3;
    int CONFIRM_BUTTON = PS4_R2;
    int BUILD_BUTTON = PS4_X; // Adjust the BUILD_BUTTON according to your configuration

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