// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

//array for hash funnction
char *arr[676] = {"aa", "ab", "ac", "ad", "ae", "af", "ag", "ah", "ai", "aj", "ak", "al", "am", "an", "ao", "ap", "aw", "ar", "as", "at", "au", "av", "aw", "ax", "ay", "az",
                  "ba", "bb", "bc", "bd", "be", "bf", "bg", "bh", "bi", "bj", "bk", "bl", "bm", "bn", "bo", "bp", "bq", "br", "bs", "bt", "bu", "bv", "bw", "bx", "by", "bz",
                  "ca", "cb", "cc", "cd", "ce", "cf", "cg", "ch", "ci", "cj", "ck", "cl", "cm", "cn", "co", "cp", "cq", "cr", "cs", "ct", "cu", "cv", "cw", "cx", "cy", "cz",
                  "da", "db", "dc", "dd", "de", "df", "dg", "dh", "di", "dj", "dk", "dl", "dm", "dn", "do", "dp", "dq", "dr", "ds", "dt", "du", "dv", "dw", "dx", "dy", "dz",
                  "ea", "eb", "ec", "ed", "ee", "ef", "eg", "eh", "ei", "ej", "ek", "el", "em", "en", "eo", "ep", "eq", "er", "es", "et", "eu", "ev", "ew", "ex", "ey", "ez",
                  "fa", "fb", "fc", "fd", "fe", "ff", "fg", "fh", "fi", "fj", "fk", "fl", "fm", "fn", "fo", "fp", "fq", "fr", "fs", "ft", "fu", "fv", "fw", "fx", "fy", "fz",
                  "ga", "gb", "gc", "gd", "ge", "gf", "gg", "gh", "gi", "gj", "gk", "gl", "gm", "gn", "go", "gp", "gq", "gr", "gs", "gt", "gu", "gv", "gw", "gx", "gy", "gz",
                  "ha", "hb", "hc", "hd", "he", "hf", "hg", "hh", "hi", "hj", "hk", "hl", "hm", "hn", "ho", "hp", "hq", "hr", "hs", "ht", "hu", "hv", "hw", "hx", "hy", "hz",
                  "ia", "ib", "ic", "id", "ie", "if", "ig", "ih", "ii", "ij", "ik", "il", "im", "in", "io", "ip", "iq", "ir", "is", "it", "iu", "iv", "iw", "ix", "iy", "iz",
                  "ja", "jb", "jc", "jd", "je", "jf", "jg", "jh", "ji", "jj", "jk", "jl", "jm", "jn", "jo", "jp", "jq", "jr", "js", "jt", "ju", "jv", "jw", "jx", "jy", "jz",
                  "ka", "kb", "kc", "kd", "ke", "kf", "kg", "kh", "ki", "kj", "kk", "kl", "km", "kn", "ko", "kp", "kq", "kr", "ks", "kt", "ku", "kv", "kw", "kx", "ky", "kz",
                  "la", "lb", "lc", "ld", "le", "lf", "lg", "lh", "li", "lj", "lk", "ll", "lm", "ln", "lo", "lp", "lq", "lr", "ls", "lt", "lu", "lv", "lw", "lx", "ly", "lz",
                  "ma", "mb", "mc", "md", "me", "mf", "mg", "mh", "mi", "mj", "mk", "ml", "mm", "mn", "mo", "mp", "mq", "mr", "ms", "mt", "mu", "mv", "mw", "mx", "my", "mz",
                  "na", "nb", "nc", "nd", "ne", "nf", "ng", "nh", "ni", "nj", "nk", "nl", "nm", "nn", "no", "np", "nq", "nr", "ns", "nt", "nu", "nv", "nw", "nx", "ny", "nz",
                  "oa", "ob", "oc", "od", "oe", "of", "og", "oh", "oi", "oj", "ok", "ol", "om", "on", "oo", "op", "oq", "or", "os", "ot", "ou", "ov", "ow", "ox", "oy", "oz",
                  "pa", "pb", "pc", "pd", "pe", "pf", "pg", "ph", "pi", "pj", "pk", "pl", "pm", "pn", "po", "pp", "pq", "pr", "ps", "pt", "pu", "pv", "pw", "px", "py", "pz",
                  "qa", "qb", "qc", "qd", "qe", "qf", "qg", "qh", "qi", "qj", "qk", "ql", "qm", "qn", "qo", "qp", "qq", "qr", "qs", "qt", "qu", "qv", "qw", "qx", "qy", "qz",
                  "ra", "rb", "rc", "rd", "re", "rf", "rg", "rh", "ri", "rj", "rk", "rl", "rm", "rn", "ro", "rp", "rq", "rr", "rs", "rt", "ru", "rv", "rw", "rx", "ry", "rz",
                  "sa", "sb", "sc", "sd", "se", "sf", "sg", "sh", "si", "sj", "sk", "sl", "sm", "sn", "so", "sp", "sq", "sr", "ss", "st", "su", "sv", "sw", "sx", "sy", "sz",
                  "ta", "tb", "tc", "td", "te", "tf", "tg", "th", "ti", "tj", "tk", "tl", "tm", "tn", "to", "tp", "tq", "tr", "ts", "tt", "tu", "tv", "tw", "tx", "ty", "tz",
                  "ua", "ub", "uc", "ud", "ue", "uf", "ug", "uh", "ui", "uj", "uk", "ul", "um", "un", "uo", "up", "uq", "ur", "us", "ut", "uu", "uv", "uw", "ux", "uy", "uz",
                  "va", "vb", "vc", "vd", "ve", "vf", "vg", "vh", "vi", "vj", "vk", "vl", "vm", "vn", "vo", "vp", "vq", "vr", "vs", "vt", "vu", "vv", "vw", "vx", "vy", "vz",
                  "wa", "wb", "wc", "wd", "we", "wf", "wg", "wh", "wi", "wj", "wk", "wl", "wm", "wn", "wo", "wp", "wq", "wr", "ws", "wt", "wu", "wv", "ww", "wx", "wy", "wz",
                  "xa", "xb", "xc", "xd", "xe", "xf", "xg", "xh", "xi", "xj", "xk", "xl", "xm", "xn", "xo", "xp", "xq", "xr", "xs", "xt", "xu", "xv", "xw", "xx", "xy", "xz",
                  "ya", "yb", "yc", "yd", "ye", "yf", "yg", "yh", "yi", "yj", "yk", "yl", "ym", "yn", "yo", "yp", "yq", "yr", "ys", "yt", "yu", "yv", "yw", "yx", "yy", "yz",
                  "za", "zb", "zc", "zd", "ze", "zf", "zg", "zh", "zi", "zj", "zk", "zl", "zm", "zn", "zo", "zp", "zq", "zr", "zs", "zt", "zu", "zv", "zw", "zx", "zy", "zz"\
                 };


//Wordcount of dicitionary
unsigned int wordcount = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    node *p = table[index];
    while (p != NULL)
    {
        if (strcasecmp(p -> word, word) == 0)
        {
            return true;
        }
        p = p -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    char temp1, temp2 = '\0';
    int diff, diff1;

    //Make first letter small for comparision
    if ((int) word[0] >= 65 && (int) word[0] <= 90)
    {
        temp1 = (int) word[0] + 32;
    }
    else
    {
        temp1 = word[0];
    }

    //Make second letter small for comparision
    if ((int) word[1] >= 65 && (int) word[1] <= 90)
    {
        temp2 = (int) word[1] + 32;
    }
    else if (word[1] != '\0' && word[1] != '\'')
    {
        temp2 = word[1];
    }
    
    
    if (temp1 == arr[0][0] && temp2 == '\0')
    {
        return 0;
    }
    else if (temp2 == '\0')
    {
        diff = (int)temp1 - (int)arr[0][0];
        return ((26 * diff));
    }
    else if (temp1 == arr[0][0])
    {
        if (temp2 == arr[0][1])
        {
            return 0;
        }
        else
        {
            diff = (int)temp2 - (int)arr[0][1];
            return (diff);
        }
    }
    else
    {
        if (temp2 == arr[0][1])
        {
            diff = (int)temp1 - (int)arr[0][0];
            return (26 * diff);
        }
        else
        {
            diff = (int)temp1 - (int)arr[0][0];
            diff1 = (int)temp2 - (int)arr[0][1];
            return ((diff * 26) + diff1);
        }
    }
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    int a, indextemp;
    node *temp;
    char *tempword = (char *)malloc((LENGTH + 2) * sizeof(char));
    FILE *dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        printf("Error loading dictionary.");
        fclose(dic);
        free(tempword);
        return false;
    }
    for (a = 0; a < 676; a++)
    {
        table[a] = (node *)malloc(sizeof(node));
        table[a] -> next = NULL;
    }

    while (fgets(tempword, LENGTH + 2, dic) != NULL)
    {
        for (a = 0; a < strlen(tempword); a++)
        {
            if (tempword[a] == '\n')
            {
                tempword[a] = '\0';
            }
        }

        a = hash(tempword);
        if (table[a] -> next == NULL)
        {
            table[a] -> next = (node *)malloc(sizeof(node));
            table[a] -> next -> next = NULL;
            indextemp = a;
            temp = table[a] -> next;
            strcpy(table[a] -> word, tempword);
        }
        else if (indextemp == a)
        {
            strcpy(temp -> word, tempword);
            temp -> next = (node *)malloc(sizeof(node));
            temp = temp -> next;
        }
        else
        {
            temp -> next = table[a] -> next;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = (node *)malloc(sizeof(node));
            temp -> next -> next = NULL;
        }
        wordcount++;
    }
    fclose(dic);
    free(tempword);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wordcount == 0)
    {
        return 0;
    }
    else
    {
        return (wordcount);
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *temp1, *temp2;
    for (int i = 0; i < 676; i++)
    {
        temp2 = table[i] -> next;
        free(table[i]);
        while (temp2 != NULL)
        {
            temp1 = temp2;
            temp2 = temp2 -> next;
            free(temp1);
        }
    }
    return true;
}