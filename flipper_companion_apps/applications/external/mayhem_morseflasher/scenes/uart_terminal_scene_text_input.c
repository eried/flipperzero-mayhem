#include "../uart_terminal_app_i.h"

void uart_terminal_scene_text_input_callback(void* context) {
    UART_TerminalApp* app = context;

    view_dispatcher_send_custom_event(app->view_dispatcher, UART_TerminalEventStartConsole);
}

void uart_terminal_scene_text_input_on_enter(void* context) {
    UART_TerminalApp* app = context;

    if(false == app->is_custom_tx_string) {
        // Fill text input with selected string so that user can add to it
        size_t length = strlen(app->selected_tx_string);
        furi_assert(length < UART_TERMINAL_TEXT_INPUT_STORE_SIZE);
        bzero(app->text_input_store, UART_TERMINAL_TEXT_INPUT_STORE_SIZE);
        strncpy(app->text_input_store, app->selected_tx_string, length);

        // Add space - because flipper keyboard currently doesn't have a space
        //app->text_input_store[length] = ' ';
        app->text_input_store[length + 1] = '\0';
        app->is_custom_tx_string = true;
    }

    // Setup view
    TextInput* text_input = app->text_input;
    // Add help message to header
    text_input_set_header_text(text_input, "Send new morse message");
    text_input_set_result_callback(
        text_input,
        uart_terminal_scene_text_input_callback,
        app,
        app->text_input_store,
        UART_TERMINAL_TEXT_INPUT_STORE_SIZE,
        false);

    text_input_add_illegal_symbols(text_input);

    view_dispatcher_switch_to_view(app->view_dispatcher, UART_TerminalAppViewTextInput);
}

bool uart_terminal_scene_text_input_on_event(void* context, SceneManagerEvent event) {
    UART_TerminalApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        if(event.event == UART_TerminalEventStartConsole) {
            // Point to custom string to send
            app->selected_tx_string = app->text_input_store;
            scene_manager_next_scene(app->scene_manager, UART_TerminalAppViewConsoleOutput);
            consumed = true;
        }
    }

    return consumed;
}

void uart_terminal_scene_text_input_on_exit(void* context) {
    UART_TerminalApp* app = context;

    text_input_reset(app->text_input);
}
