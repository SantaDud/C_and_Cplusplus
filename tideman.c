/*#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    int a = 0;
    float b = 0, words = 0, letters = 0, sentences = 0;
    char text[5000];
    text[0] = 'a';
    printf("Text: ");
    while ((text[a] = getchar()) != '\n')                      //Infinite loop, takes input as long as the user doesn't pres enter
    {
        if (text[a] == ' ')           //condition to check if the words have increased
        {
            ++words;
        }
        if (text[a] == ' ' && (text[a - 1] == '.' || text[a - 1] == '?' || text[a - 1] == '!'))   //condition that checks if number of sentences have increased
        {
            ++sentences;
        }
        if (text[a] != ' ' && text[a] != '!' && text[a] != '?' && text[a] != '"' && text[a] != ',' && text[a] != '.'
            && text[a] != '\'' && text[a] != ';')         //condition that increases the number of letters
        {
            letters++;
        }
        a++;
    }
    ++words;               //increment in words and sentences for logical reasons
    ++sentences;
    letters /= words;
    letters *= 100;
    sentences /= words;
    sentences *= 100;
    b = 0.0588 * letters - 0.296 * sentences - 15.8;          //calculation of Coleman - Liau index
    if (b > 16)
    {
        printf("Grade 16+\n");
    }
    else if (b < 1)
    {
        printf("Below grade 1\n");
    }
    else
    {
        printf("Grade: %.1f", round(b));
    }
}*/




/*#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int a = 0, b = 1, c = 0, d = 0;             //initializing variables
    char text[50000], temp[26], ch = 'a';                 //text[] is a char array in which plaintext will be saved
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    if (argv[1][26] != '\0')               //condition which prints error if command line argument is not long enough or longer than required
    {
        printf("Key must contain 26 letters.");
        return 1;
    }
    for (c = 0; c < 26; c++)
    {
       temp[c] = argv[1][c];
        for (d = b; d < 26; d++)
        {
            if (temp[c] == argv[1][d])                            //NO NEED FOR EXTRA ARRAY
            {
                printf("Usage of duplicate characters in key.");
                return 1;
            }
        }
        b++;
        if (!(((int) argv[1][c] >= 65 && (int) argv[1][c] <= 90) || ((int) argv[1][c] >= 97
                                      && (int) argv[1][c] <= 122)))                         //condition checks the command line argument for errors
        {
            printf("Usage: ./substitution key");
            return 1;
        }
    }
    if (argc == 2 && argv[1][26] == '\0')                  //condition if command line argument is okay
    {
        printf("plaintext: ");
        while ((text[a] = getchar()) != '\n')               //loop takes in characters while the user does not press enter
        {
            if ((int) text[a] >= 48 && (int) text[a] <= 57)    //condition checks if the character entered was a number
            {
                a++;
            }
            else if (text[a] != ' ' && text[a] != '.' && text[a] != ',' && text[a] != '\'' && text[a] != '"' && text[a] != '!'
                     && text[a] != '?')                          //condition that checks for punctuation
            {
                b = 1;
                ch = 'a';
                c = 0;
                if ((int) text[a] >= 65 && (int) text[a] <= 90)         //condition checks whether the entered letter was capitalized
                {
                    d = 1;
                    text[a] = (int) text[a] + 32;                   //letter turned to a small letter
                }
                else
                {
                    d = 0;
                }
                while ((int) text[a] != (int) ch)               //a loop which tests the character input with all the letters of english alphabet
                {
                    ch = (int)ch + b;
                    ++c;
                }
                if (d == 1 && ((int) argv[1][c] >= 97
                               && (int) argv[1][c] <= 122))          //condition which changes the command line argument letter to capital if needed
                {
                    argv[1][c] = (int) argv[1][c] - 32;
                    text[a] = argv[1][c];
                    a++;
                    argv[1][c] = (int) argv[1][c] + 32;
                }
                else if (d == 0 && ((int) argv[1][c] >= 65
                                    && (int) argv[1][c] <= 90))       //condition which changes the command line argument letter small if needed
                {
                    argv[1][c] = (int) argv[1][c] + 32;
                    text[a] = argv[1][c];
                    argv[1][c] = (int) argv[1][c] - 32;
                    a++;
                }
                else                                        //default condition
                {
                    text[a] = argv[1][c];
                    a++;
                }
            }
            else
            {
                a++;                            //default condition
            }
        }
        printf("ciphertext: ");
        for (b = 0; b < a; b++)                 //loop prints ciphered text
        {
            printf("%c", text[b]);
        }
        printf("\n");
        return 0;
    }
}*/



/*#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    int i;
    for (i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int i = 0, j = 1, largest[9], c, d = 0;
    while (i < candidate_count)
    {
        c = 1;
        while (j < candidate_count)
        {
            if (candidates[j].votes > candidates[i].votes)
            {
                largest[0] = j;
                i = j;
                j++;
                c = 0;
                d = 1;
                break;
            }
            j++;
        }
        //break the loop if first candidate has the most votes
        if (c == 1 && d == 0)
        {
            largest[0] = i;
            break;
        }
        else if (c == 1)
        {
            i++;
        }
    }
    i = largest[0] + 1;
    j = 1;
    while (i < candidate_count)
    {
        if (candidates[largest[0]].votes == candidates[i].votes)
        {
            largest[j] = i;
            j++;
        }
        i++;
    }
    for (i = 0; i < j; i++)
    {
        printf("%s\n", candidates[largest[i]].name);
    }
    return;
}*/



/*#include <cs50.h>
#include <stdio.h>
#include<string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool check_circle(int loser, int winner, int i);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    int i;
    for (i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int i, j, k;
    for (i = 0; i < candidate_count; i++)
    {
        k = 1;
        for (j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[i + k]]++;
            k++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int i, j, k = 0;
    for (i = 0; i < candidate_count; i++)
    {
        for (j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
                pair_count++;
                k++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[k].winner = j;
                pairs[k].loser = i;
                pair_count++;
                k++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int i, j, strenght1, strenght2;
    pair temp;
    for (i = 0; i < pair_count; i++)
    {
        strenght1 = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        for (j = 0; j < pair_count; j++)
        {
            strenght2 = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
            if (strenght1 < strenght2 && i < j)
            {
                temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
            else if (strenght1 > strenght2 && j < i)
            {
                temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int i, a = 0;
    for (i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        if (check_circle(pairs[i].loser, pairs[i].winner, i) == true)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }    
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int i, j, k;
    for (i = 0; i < candidate_count; i++)
    {
        k = 0;
        for (j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                k++;
                if (k == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                    return;
                }
            }
        }
    }
    return;
}
bool check_circle(int loser, int winner, int i)
{
    int a;
    for (a = 0; a < i; a++)
    {
        if (pairs[a].winner == loser)
        {
            if (pairs[a].loser == winner)
            {
                return true;
            }
            if (check_circle(pairs[a].loser, winner, i) == false)
            {
                return false;
            }
            else if (check_circle(pairs[a].loser, winner, i) == true)
            {
                return true;
            }
        }
    }
    return false;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    char *str;
    FILE *ptr = fopen("text.txt","a");
    fprintf(ptr, "frick");
    fclose(ptr);
}