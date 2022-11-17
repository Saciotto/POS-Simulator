
target_sources(gui PRIVATE 
    # Sources
    assets/font_montserrat_14.c
    assets/font_montserrat_26.c
    assets/font_roboto_14.c
    assets/font_roboto_18.c
    assets/img_logo.c
    assets/img_signal_0.c
    assets/img_signal_1.c
    assets/img_signal_2.c
    assets/img_signal_3.c
    assets/img_signal_4.c
    assets/img_signal_5.c
    assets/img_wifi_0.c
    assets/img_wifi_1.c
    assets/img_wifi_2.c
    assets/img_wifi_3.c
    components/comp_body.c
    components/comp_title_bar.c
    views/gui_idle.c
    views/gui_menu.c
    gui_status_bar.c
    gui_theme.c

    # Headers
    gui_assets.h
    gui_components.h
    gui_dimensions.h
)

target_include_directories(gui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
