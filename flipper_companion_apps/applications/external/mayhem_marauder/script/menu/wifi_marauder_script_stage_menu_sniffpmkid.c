#include "../../wifi_marauder_app_i.h"

static void wifi_marauder_sniffpmkid_stage_hop_channels_setup_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    variable_item_set_current_value_index(item, stage->hop_channels);
}

static void wifi_marauder_sniffpmkid_stage_hop_channels_change_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);

    uint8_t current_stage_index = variable_item_list_get_selected_item_index(app->var_item_list);
    const WifiMarauderScriptMenuItem* menu_item =
        &app->script_stage_menu->items[current_stage_index];

    uint8_t option_index = variable_item_get_current_value_index(item);
    variable_item_set_current_value_text(item, menu_item->options[option_index]);

    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    stage->hop_channels = option_index;
}

static void wifi_marauder_sniffpmkid_stage_force_deauth_setup_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    variable_item_set_current_value_index(item, stage->force_deauth);
}

static void wifi_marauder_sniffpmkid_stage_force_deauth_change_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);

    // Get menu item
    uint8_t current_stage_index = variable_item_list_get_selected_item_index(app->var_item_list);
    const WifiMarauderScriptMenuItem* menu_item =
        &app->script_stage_menu->items[current_stage_index];

    // Defines the text of the selected option
    uint8_t option_index = variable_item_get_current_value_index(item);
    variable_item_set_current_value_text(item, menu_item->options[option_index]);

    // Updates the attribute value of the current stage
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    stage->force_deauth = option_index;
}

static void wifi_marauder_sniffpmkid_stage_channel_setup_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    if(stage->channel >= 0 && stage->channel < 12) {
        variable_item_set_current_value_index(item, stage->channel);
    } else {
        variable_item_set_current_value_index(item, 0);
    }
}

static void wifi_marauder_sniffpmkid_stage_channel_change_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);

    // Get menu item
    uint8_t current_stage_index = variable_item_list_get_selected_item_index(app->var_item_list);
    const WifiMarauderScriptMenuItem* menu_item =
        &app->script_stage_menu->items[current_stage_index];

    // Defines the text of the selected option
    uint8_t option_index = variable_item_get_current_value_index(item);
    variable_item_set_current_value_text(item, menu_item->options[option_index]);

    // Updates the attribute value of the current stage
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    stage->channel = option_index;
}

static void wifi_marauder_sniffpmkid_stage_timeout_setup_callback(VariableItem* item) {
    WifiMarauderApp* app = variable_item_get_context(item);
    WifiMarauderScriptStageSniffPmkid* stage = app->script_edit_selected_stage->stage;
    char timeout_str[32];
    snprintf(timeout_str, sizeof(timeout_str), "%d", stage->timeout);
    variable_item_set_current_value_text(item, timeout_str);
}

static void wifi_marauder_sniffpmkid_stage_timeout_select_callback(void* context) {
    WifiMarauderApp* app = context;
    WifiMarauderScriptStageSniffPmkid* stage_sniffpmkid = app->script_edit_selected_stage->stage;
    app->user_input_number_reference = &stage_sniffpmkid->timeout;
}

void wifi_marauder_script_stage_menu_sniffpmkid_load(WifiMarauderScriptStageMenu* stage_menu) {
    stage_menu->num_items = 4;
    stage_menu->items = malloc(4 * sizeof(WifiMarauderScriptMenuItem));

    stage_menu->items[0] = (WifiMarauderScriptMenuItem){
        .name = strdup("Force deauth"),
        .type = WifiMarauderScriptMenuItemTypeOptionsString,
        .num_options = 2,
        .options = {"no", "yes"},
        .setup_callback = wifi_marauder_sniffpmkid_stage_force_deauth_setup_callback,
        .change_callback = wifi_marauder_sniffpmkid_stage_force_deauth_change_callback};
    stage_menu->items[1] = (WifiMarauderScriptMenuItem){
        .name = strdup("Channel"),
        .type = WifiMarauderScriptMenuItemTypeOptionsNumber,
        .num_options = 12,
        .options = {"none", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"},
        .setup_callback = wifi_marauder_sniffpmkid_stage_channel_setup_callback,
        .change_callback = wifi_marauder_sniffpmkid_stage_channel_change_callback};
    stage_menu->items[2] = (WifiMarauderScriptMenuItem){
        .name = strdup("Timeout"),
        .type = WifiMarauderScriptMenuItemTypeNumber,
        .num_options = 1,
        .setup_callback = wifi_marauder_sniffpmkid_stage_timeout_setup_callback,
        .select_callback = wifi_marauder_sniffpmkid_stage_timeout_select_callback};
    stage_menu->items[3] = (WifiMarauderScriptMenuItem){
        .name = strdup("Hop Channels"),
        .type = WifiMarauderScriptMenuItemTypeOptionsString,
        .num_options = 2,
        .options = {"no", "yes"},
        .setup_callback = wifi_marauder_sniffpmkid_stage_hop_channels_setup_callback,
        .change_callback = wifi_marauder_sniffpmkid_stage_hop_channels_change_callback};
}