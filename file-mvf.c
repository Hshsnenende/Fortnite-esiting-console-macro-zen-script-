define Input_Interval = 25; // Input interval for new gen consoles

init {
    // Define the edit button for Cronus Zen (PS4 Controller)
    int EDIT_BUTTON = PS4_TOUCH; // Edit button for initial edit action

    // Define the soft aim button
    int SOFT_AIM_BUTTON = PS4_CIRCLE; // Soft aim button (example: Circle button)
    int soft_aim_enabled = FALSE; // Soft aim status (disabled by default)
}

main {
    if(get_val(PS4_RIGHT)) {
        // Automated edit selection loop
        combo_run(EDIT_LOOP);
    } else {
        combo_stop(EDIT_LOOP);
    }
    
    // Toggle Soft Aim
    if(event_press(SOFT_AIM_BUTTON)) {
        soft_aim_enabled = !soft_aim_enabled; // Toggle soft aim status
    }

    // Soft Aim Functionality
    if(soft_aim_enabled) {
        activate_soft_aim(); // Call the soft aim function
    }
    
    // Instant Building for Structures (unchanged)
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

function activate_soft_aim() {
    // Soft Aim logic goes here
    // Implement your soft aim behavior
    // This function will be called when soft aim is enabled
    // Example: Adjusting aim sensitivity or assist
    // Example: Slow down aim movement for smoother targeting
}

// Other combos remain unchanged