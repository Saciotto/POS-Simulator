
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
    components/body.c
    components/icons.c
    components/status_bar.c
    components/title_bar.c
    views/idle.c
    views/menu.c
    theme.c

    # Headers
    assets.h
    components.h
    dimensions.h
    theme.h
)

target_include_directories(gui PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
