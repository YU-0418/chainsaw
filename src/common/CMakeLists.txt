target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

message("!!PROJECT_NAME is ${PROJECT_NAME}")

target_sources(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/chartool.cpp)

 