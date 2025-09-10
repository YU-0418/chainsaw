target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_sources(${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/chartool.cpp
    ${CMAKE_CURRENT_LIST_DIR}/command.cpp
    ${CMAKE_CURRENT_LIST_DIR}/option.cpp
    ${CMAKE_CURRENT_LIST_DIR}/print.cpp
    ${CMAKE_CURRENT_LIST_DIR}/read_config_message.cpp
    ${CMAKE_CURRENT_LIST_DIR}/readwritefile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/stringtool.cpp
    )
