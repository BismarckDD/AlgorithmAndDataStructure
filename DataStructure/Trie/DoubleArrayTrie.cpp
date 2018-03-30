#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

#define MIN_CODE 1
#define MAX_CODE 255
#define CHAR_NUM 26

class DoubleArrayTrie
{
    private:
        int *m_base;
        int *m_check;
        int m_capacity;
        int m_pos;
        int m_tailPos;
        const int m_inc;

        char *m_tail;
        int m_tailMax;
        const int m_tailInc;
        char *m_temp;
        int m_tempMax;
        const int m_tempInc;
        
        int base(int n);
        int check(int n);
        void w_base(int n, int value);
        void w_check(int n, int value);
        int x_check(char *);
        void realloc_bc();
        char *malloc_str(char const *, int& , int );
        char *realloc_str(char const*, char *, int&, int );
        void read_tail(int n);
        void write_tail(char *temp, int n);

        char *set_list(int );
        int arc_index(char );
        void bc_insert(int, char *);
        int bc_change(int, int, char *, char);
        void tail_insert(int, char *, char *);
        void separate(int, char *, int);

    public:
        DoubleArrayTrie(int p_inc = 10)
            : m_inc(p_inc),
              m_tailInc(p_inc),
              m_tempInc(p_inc)
        {
            m_capacity = m_inc;
            m_pos = 1;
            m_tailPos = 1;
            m_base =  (int *)malloc(sizeof(int) * m_capacity);
            m_check = (int *)malloc(sizeof(int) * m_capacity);

            if(m_base == NULL || m_check == NULL) 
            {
                cout << "Malloc BC Failed!" << endl;
                exit(-1);
            }

            for(int i = 0; i < m_capacity; ++i) 
            {
                m_base[i] = 0;
                m_check[i] = 0;
            }

            w_base(1, 1);
            m_pos = 1;

            m_tail = malloc_str(string("TAIL").c_str(), m_tailMax, m_tailInc);
            m_tail[0] = '#';
            m_temp = malloc_str(string("TEMP").c_str(), m_tailMax, m_tempInc);
        }

        ~DoubleArrayTrie()
        {
            if(m_base != NULL)
            {
                free(m_base);
                m_base = NULL;
            }

            if(m_check != NULL)
            {
                free(m_check);
                m_check = NULL;
            }

            if(m_tail != NULL)
            {
                free(m_tail);
                m_tail = NULL;
            }
        }

        bool add(char *);
        bool remove(char *);
        int find(char *);
};

bool DoubleArrayTrie::add(char *p_word) 
{
    int h = -1, s = 1, t;

    cout << "begin-insert word: " << p_word << endl;

    strcat(p_word, "#");
    do {

        t = base(s) + (unsigned char)(p_word[++h]);

        /*
         * check(t) == 0 => insert directly.
         * check(t) != 0 => reallocate base.
         *
         * */
        if(check(t) != s) 
        {
            cout << "s=" << s << ", t=" << t << ", check(t)=" << check(t) << endl; 
            bc_insert(s, p_word + h);
            cout << "end-insert word: " << p_word << endl;
            return 1;
        }

        /*
         * need to deal with tail
         *
         * */
        if(base(t) < 0) 
        {
            break;
        }

        s = t;
    } while(p_word[h]);

    if(p_word[h] != '#')
    {   //Need to judge tail str.
        read_tail((-1) * base(t));
    }

    if(p_word[h] == '#' || strcmp(m_temp, p_word + h + 1) == 0) 
    {   //No need to further operation.
        cout << "end-insert word(be a prefix of a existing word.): " << p_word << endl;
        return 1;
    } 

    if(base(t) != 0) 
    {   //Seems to be execute finally.
        tail_insert(t, m_temp, p_word + h + 1);
        cout << "end-insert word: " << p_word << endl;
    }
    return true;
}

bool DoubleArrayTrie::remove(char *p_word) 
{ 
    int t = find(p_word);
    if(t = -1) 
    {
        return false;
    } 
    else 
    {
        w_base(t, 0);
        w_check(t, 0);
        return true;
    }
}

int DoubleArrayTrie::find(char *p_word) 
{ 
    int h = -1, s = 1, t;

    cout << "begin-search word: " << p_word << endl; 

    do {

        t = base(s) + (unsigned char)(p_word[++h]);

        if(check(t) != s) 
        {
            cout << "end-search word: " << p_word << endl; 
            return -1;
        }

        if(base(t) < 0) 
        {
            break;
        }

        s = t;

    } while(p_word[h]);

    if(p_word[h] != '#')
    {
        read_tail((-1) * base(t));
    }

    if(p_word[h] == '#' || strcmp(m_temp, p_word + h + 1) == 0) 
    {
        cout << "end-search word: " << p_word << endl;
        return t;
    } 
    else 
    {
        cout << "end-search word: " << p_word << endl;
        return -1;
    }
}

/*
 * Getter and Setter method of base and check
 *
 * */
int DoubleArrayTrie::base(int n) 
{
    if(n > m_pos) 
    {
        return 0;
    } 
    else 
    {
        cout << "read base index=" << n << ", value="<< m_base[n] << endl;
        return m_base[n];
    }
}

int DoubleArrayTrie::check(int n) 
{
    if(n > m_pos)
    {
        return 0;
    } 
    else 
    {
        cout << "read check index=" << n << ", value="<< m_check[n] << endl;
        return m_check[n];
    }
}

void DoubleArrayTrie::w_base(int n, int value) 
{
    while(n >= m_capacity) 
    {
        realloc_bc();
    }

    if(n > m_pos)
    {
        m_pos = n;
    }

    m_base[n] = value; 
    cout << "write base index=" << n << ", value="<< m_base[n] << endl;
}

void DoubleArrayTrie::w_check(int n, int value) 
{
    while(n >= m_capacity)
    {
        realloc_bc();
    }

    if(n > m_pos) 
    {
        m_pos = n;
    }

    m_check[n] = value; 
    cout << "write check index=" << n << ", value="<< m_check[n] << endl;
}

/*
 * malloc a str
 *
 * */
char *DoubleArrayTrie::malloc_str(const char *area_name, int& capacity, int init) 
{
    capacity = init;
    char *area = (char *)malloc(sizeof(char) * capacity);

    if(area == NULL) 
    {
        cout << area_name << " Malloc string Failed!!" << endl;
        exit(-1);
    }

    for(int i = 0; i < capacity; ++i)
    {
        area[i] = '\0';
    }

    cout << area_name << " Realloc string Succeed!" << endl;
    return area;
}

/*
 * realloc a str
 *
 * */
char *DoubleArrayTrie::realloc_str(char const *area_name, char *area, int& capacity, int inc) 
{
    int pre_capacity = capacity;
    capacity += inc;
    area = (char *)realloc(area, sizeof(char) * capacity);

    if(area == NULL) 
    {
        cout << area_name << " Realloc string Failed!" << endl;
        exit(-1);
    }

    for(int i = pre_capacity; i < capacity; ++i)
    {
        area[i] = '\0';
    }

    cout << area_name << " Realloc string Succeed!" << endl;
    return area;
}

/*
 * char to index(int)
 *
 * */
int DoubleArrayTrie::arc_index(char ch)
{
    return ch - 'a' + 2;
}

/*
 * Simple Increase the capacity of BC
 * 
 * */
void DoubleArrayTrie::realloc_bc() 
{
    int pre_capacity = m_capacity;
    m_capacity += m_inc;
    m_base  = (int *)realloc(m_base,  sizeof(int)*m_capacity);
    m_check = (int *)realloc(m_check, sizeof(int)*m_capacity);
    if(m_base == NULL || m_check == NULL) 
    {
        cout << "Realloc base & check Failed!" << endl;
        exit(-1);
    }

    for(int i = pre_capacity; i < m_capacity; ++i) 
    {
        m_base[i]  = 0;
        m_check[i] = 0;
    }

    cout << "Realloc base & check Succeed!" << endl;
}


/*
 * read tail to temp
 *
 * */
void DoubleArrayTrie::read_tail(int p) 
{
    int i = 0;
    while(m_tail[p] != '#') 
    {
        m_temp[i++] = m_tail[p++];
    }

    m_temp[i++] = '#';
    m_temp[i] = '\0';

    cout << "Read tail string complete!" << endl;
}

/*
 * write temp to tail
 *
 * */
void DoubleArrayTrie::write_tail(char *temp, int p) 
{
    int i = 0;
    while((p + strlen(temp)) >= m_tailMax - 1) 
    {
        m_tail = realloc_str(string("TAIL").c_str(), m_tail, m_tailMax, m_tailInc);
    }

    while(temp[i] != '\0') 
    {
        m_tail[p++] = temp[i++];
    }

    if(p + 1 > m_tailPos) 
    {
        m_tailPos = p;
    }

    cout << "Write tail string complete!" << endl;
}

int DoubleArrayTrie::x_check(char *list) 
{
    int i = 0, base_pos = 1, check_pos;
    unsigned char ch;

    cout << "x_check start: " << endl;

    do {
        ch = list[i++];
        check_pos = base_pos + ch;

        if(check(check_pos) != 0) 
        {
            ++base_pos;
            i = 0;
            continue;
        }
    } while(list[i] != '\0');

    cout << "x_check end!" << endl;

    return base_pos;
}

char *DoubleArrayTrie::set_list(int s) 
{
    char *list = (char*)malloc(MAX_CODE + 1 + 1); // 256个字符 + 1 '\0'
    int i, j = 0, t;
    for(i = MIN_CODE; i < MAX_CODE; ++i) 
    {
        t = base(s) + i;
        if(check(t) == s) 
        {
            list[j] = (unsigned char)i; //change
            j++;
        }
    }
    list[j] = '\0';

    cout << "set_list: " << list << endl;

    return list;
}

void DoubleArrayTrie::separate(int s, char *b, int tail_pos) 
{
    int t = base(s) + (unsigned char)(*b); // change
    b++;
    w_check(t, s);
    w_base(t, (-1) * tail_pos);
    write_tail(b, tail_pos);
}

void DoubleArrayTrie::bc_insert(int s, char *b) 
{
    int t;
    char list_s[MAX_CODE + 2];
    char list_t[MAX_CODE + 2];

    cout << "bc_insert start: " << endl;

    t = base(s) + (unsigned char)(*b);
    cout << "t=" << t << " check(t)=" << check(t) << endl;
    /*
     * check[t] == 0 Insert
     * chect[t] != 0
     * */
    if(check(t) != 0) 
    {
        strcpy(list_s, set_list(s));
        strcpy(list_t, set_list(check(t)));
        if(strlen(list_s) + 1 < strlen(list_t)) 
        {
            cout << "list_s=" << list_s << endl;
            s = bc_change(s, s, list_s, *b);
        } 
        else 
        {
            cout << "list_t=" << list_t << endl;
            s = bc_change(s, check(t), list_t, '\0');
        }
    }//conflict, reallocate base and check value.

    separate(s, b, m_tailPos);
    cout << "bc_insert end." << endl;
}

int DoubleArrayTrie::bc_change(int current, int s, char *list, char ch) 
{
    int i, k, old_node, new_node, old_base;
    char a_list [MAX_CODE + 2];

    old_base = base(s);

    if(ch != '\0') 
    {
        strcpy(a_list, list);
        i = strlen(a_list);
        a_list[i] = ch;
        a_list[i + 1] = '\0';
    } 
    else 
    {
        strcpy(a_list, list);
    }

    w_base(s, x_check(a_list));
    i = 0;
    do {
        old_node = old_base + (unsigned char)(*list); //change
        new_node = base(s) + (unsigned char)(*list);
        cout << "old_node=" << old_node << ",new_node=" << new_node << endl; 
        w_base(new_node, base(old_node));
        w_check(new_node, s);
        if(base(old_node) > 0) 
        {
            k = base(old_node) + 1;
            while(k - base(old_node) <= MAX_CODE || k < m_pos) 
            {
                if(check(k) == old_node) 
                {
                    w_check(k, new_node);
                }
                ++k;
            }
        }

        if(current != s && old_node == current) 
        {
            current = new_node;
        }

        w_base(old_node, 0);
        w_check(old_node, 0);
        list++;
    } while(*list != '\0');
    return current;
}

void DoubleArrayTrie::tail_insert(int s, char *a, char *b) 
{
    char list[3];
    unsigned char ch;
    int i = 0, length = 0, t;
    int old_tail_pos;
    old_tail_pos = (-1) * base(s);
    cout << "tail_insert:" << "s=" << s << "a=" << a << " b=" << b << endl;

    while(a[length] == b[length])
    {
        length++;
    }

    while(i < length) 
    {
        ch = a[i++];
        list[0] = ch;
        list[1] = '\0';
        w_base(s, x_check(list));
        t = base(s) + (unsigned char)(ch);
        w_check(t, s);
        s = t;
    }
    list[0] = a[length];
    list[1] = b[length];
    list[2] = '\0';
    w_base(s, x_check(list));
    separate(s, a + length, old_tail_pos);
    separate(s, b + length, m_tailPos);
}


//Simple test
int main() 
{
    DoubleArrayTrie dart;
    char word[30] = {'\0'};
    FILE *key_file = fopen("key_words.txt", "r");

    if(key_file == NULL) 
    {
        cout << "open key file error!" << endl;
        return -1;
    }

    while(fscanf(key_file, "%s", word) != EOF) 
    {
        dart.add(word);
        cout << endl;
    }

    strcpy(word, "Beijing#");

    if(dart.find(word) > 0) 
    {
        printf("find word!\n");
    } 
    else 
    {
        printf("not find word!\n");
    }

    return 0;
}
