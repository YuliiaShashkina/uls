#ifndef ULS_H
#define ULS_H

#include "libmx.h"

#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <string.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/errno.h>

#define MX_FLAGS "ACFOSTGacdgfilmorsptux1@"
#define MX_NOCOLOR "\033[0m"  // nocolor
#define MX_RED "\033[0;31m"  // --x--x--x 3
#define MX_SOCKET "\033[0;32m"  // SOCKET
#define MX_PIPE "\033[0;33m"  // PIPE
#define MX_DIRCOLOR "\033[0;34m"  // DIR d3
#define MX_LINK "\033[0;35m"  // LINK
#define MX_BLOK "\033[34;46m"  // BLOK
#define MX_CHARACTER "\033[34;43m"  // CHARACTER
#define MX_UIDBIT "\033[30;41m"  // --s------ 1
#define MX_GIDBIT "\033[30;46m"  // -----s--- 2
#define MX_STICKYBIT "\033[30;42m"  // -------wT(t) d1
#define MX_NOTSTICKYBIT "\033[30;43m"  // -------w- d2
#define MX_HALF_YEAR 15768000
#define MX_MINOR(x) ((x) & 0xFFFFFF)
#define MX_MAJOR(x) (((x) >> 24) & 0xFF)

typedef enum e_errors
{
    INVALID_ARGV,
    INVALID_FLAGS
}            t_errors;

typedef struct s_data_const
{
    time_t time;
    char *ful_n;
    char *stracl;
    char *name;
    char *name_c;
    char *strrwx;
    char *strtime;
    char *strlink;
    char *strgid;
    char *struid;
    char *strmaj;
    char *strmin;
    char *strlinkcount;
    char *strbytes;
    char *strblocks;
    char *strino;
    char *color;
    char *flag_f;
    char *flags;
    char *acltext;
    char *strxattr;
    char *inoattr;
    int xattr;
    int min;
    int maj;
    long nsec;
    long long ino;
    long rdev;
    long dev;
    long size_bytes;
    long link;
    long blocks;
    struct s_data_const *next;
}              t_const;

typedef struct s_sort_list
{
    t_const *cnst;
    struct s_sort_list *next;
}              t_sort;

typedef struct s_dir
{
    char *name;
    t_const *cnst;
    struct s_dir *next;
}              t_dir;

typedef struct s_big_data
{
    t_const *cnst;
    t_sort *sort;
    t_dir *dir;
    char *strtotal;
    char **name_all;
    char **file;
    int *flags;
    char *path;
    bool isattyflag;
    int colums;
    int flag_total;
    int size;
    int size_all;
    int width;
    bool flag_minmaj;
    int max_len_name;
    int max_len_uid;
    int max_len_gid;
    int max_len_bytes;
    int max_len_link;
    int max_len_min;
    int max_len_maj;
    int max_len_ino;
    int max_len_blocks;
    int max_len_flags;
    int len_ttr;
    bool acl;
    int total;
    int errors;
    bool link;
    struct s_big_data *next;
    char **dir_arr;
    char *str;
    char *dir_name;
}              t_data;

void mx_print_x(t_data *data);
void mx_get_flags_for_file(t_const *cnst, struct stat st);
int mx_print_flag_f(char *str, t_data *data);
void mx_get_flag_f(t_const *cnst);
void mx_color(t_const *cnst);
void mx_print_m(t_data *data);
void mx_sort_dir(t_dir *dir, t_data *data);
void mx_sort_dir_alp(t_dir *dir);
int mx_flag_link(t_data *data);
void mx_one_argument(t_data *data);
void mx_sort_dir_arr(t_data *data);
bool mx_last_char(char *str);
void mx_file_argument(t_const *cnst, t_data *data);
void mx_dir_argument(t_dir *arg, t_data *data);
void mx_error_print(char *str, t_data *data);
void mx_get_file_col(t_const *data_l, t_data *data);
void mx_creat_list(t_sort *gen);
void mx_sort_time(t_sort *general);
void mx_sort_size(t_sort *gen);
void mx_sort_all(t_data *data, t_sort *general);
void mx_sort_revers(t_sort *general, t_data *data);
void mx_many_argument(t_data *data);
void mx_control_char_name(char **str);
void mx_check_control_char(char ***str);
void mx_get_data(t_data *data, t_const *cnst);
void mx_full_path(t_data *data, t_const *data_l);
void mx_printstr_update(char *str1, char *str2, char *str3, char *str4);
void mx_print_spase(int count);
void mx_sort_my_list(t_sort *gen);
void mx_print_l(t_const *cnst, t_data *data);
void mx_get_flag_l(t_const *cnst, t_data *data);
bool mx_isspecial(t_const *cnst);
bool mx_islink(t_const *cnst);
void mx_get_acl(t_const *cnst);
void mx_get_minmaj(t_const *cnst);
void mx_get_rdev(struct stat st, t_const *cnst);
void mx_get_dev(struct stat st, t_const *cnst);
void mx_get_law(struct stat st, t_const *cnst);
void mx_get_blocks(struct stat st, t_const *cnst);
void mx_get_uid(struct stat st, t_const *cnst);
void mx_get_gid(struct stat st, t_const *cnst);
void mx_get_link(struct stat st, t_const *cnst);
void mx_get_size_bytes(struct stat st, t_const *cnst);
void mx_get_ino(struct stat st, t_const *cnst);
void mx_get_time(struct stat st, t_const *cnst, t_data *data);
void mx_read_link(t_const *cnst);
void mx_get_is(t_const *cnst, t_data *data);
char *mx_itoa_sp(long long number);
void mx_print_to_file(char **file, t_data *data);
void mx_sort_file(char **str, int size);
int mx_size_a(t_data *data);
char **mx_get_result(char **file, t_data *data);
void mx_head_size(t_const *cnst, t_data *data);
int mx_columns();
void mx_print_file(t_data *data);
void mx_num_file(t_const *cnst, t_data *data);
int mx_read_dir(char *dirname, t_data *data);
void mx_flags_into_arr(char *s, t_data *app);
void mx_read_flags(char **argv, int argc, t_data *app);
void mx_count_flags_in_str(char **argv, t_data *app, int argc);
int mx_dir_arr(char **argv, int argc, t_data *app);
void mx_printerr(t_errors errors, char s);
void mx_print_error(const char *s);
void mx_check_flags(char *s, t_data *app);
void mx_basic_flags(char *cont, t_data *app);
void mx_flags_for_sort(char *cont, t_data *app);
void mx_other_flags(char *cont, t_data *app);
void mx_printerr_char(char s);
void mx_flags_into_arr(char *s, t_data *app);

#endif

