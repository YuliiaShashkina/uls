#include "uls.h"

static void get_strstr(t_const *data_l, t_data *data) {
    char **result = malloc(sizeof(char*) * (data->size_all + 1));

    for (int i = 0; i <= data->size_all; i++) {
        result[i] = NULL;
    }
    for (int j = 0; data_l != NULL; j++) {
        result[j] = data_l->name_c;
        data_l = data_l->next;
    }
    data->isattyflag = 0;
    data->name_all = mx_get_result(result, data);
    free(result);
}

static void get_str_to_file(t_const *data_l, t_data *data) {
    char **file = malloc(sizeof(char*) * (data->size + 1));

    for (int i = 0; i <= data->size; i++) {
        file[i] = NULL;
    }
    for (int j = 0; j < data->size; j++) {
        file[j] = data_l->name_c;
        data_l = data_l->next;
    }
    data->isattyflag = 1;
    data->name_all = file;
}

void mx_get_file_col(t_const *data_l, t_data *data) {
    if (((isatty(1) && !data->flags[2] && !data->flags[14]) || data->flags[17])
        && !data->flags[24]) {
        get_strstr(data_l, data);
    }
    else {
        get_str_to_file(data_l, data);
    }
}

