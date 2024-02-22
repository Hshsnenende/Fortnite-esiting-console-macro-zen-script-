// Define button mappings
int PS4_R3 = 0;
int PS4_L3 = 0;
int PS4_R2 = 0;
int PS4_R1 = 0;

// Define Edit action
combo Edit_Action {
    set_val(PS4_R3, 50);
    wait(370);
    set_val(PS4_R3, 0);
}

// Define Select action
combo Select_Action {
    wait(10);
    set_val(PS4_L3, 100);
    wait(10);
}

// Define Confirm action
combo Confirm_Action {
    wait(10);
    set_val(PS4_R2, 100);
    wait(15);
}

// Main loop
combo Main_Loop {
    while (1) {
        // Check if the right arrow button is pressed to activate the script
        if (get_val(PS4_R1)) {
            // Perform Edit, Select, and Confirm actions sequentially
            combo_run(Edit_Action);
            combo_run(Select_Action);
            combo_run(Confirm_Action);
            combo_run(Select_Action);
            combo_run(Confirm_Action);
        }
        else {
            // Reset button values when the right arrow button is released
            set_val(PS4_R3, 0);
            set_val(PS4_L3, 0);
            set_val(PS4_R2, 0);
        }
        wait(10); // Delay to prevent rapid execution
    }
}

// Run the Main Loop combo
combo RUN {
    combo_run(Main_Loop);
}