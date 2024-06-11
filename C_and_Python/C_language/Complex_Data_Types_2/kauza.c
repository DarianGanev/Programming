#include <stdio.h>
#include <stdbool.h>

struct {
    int day;
    int month;
    int year;
    struct {
        int hour;
        int minute;
    } time;
} typedef Date;

typedef struct {
    char first_name[20];
    char middle_name[20];
    char last_name[20];
    char email[50];
    char phone_number[15];
} Participant;

typedef struct {
    Participant participant;
    bool will_participate;
} ParticipantResponse;

typedef struct {
    char title[100];
    char description[500];
    Date date;
    ParticipantResponse participants[100];
    int num_participants;
} Cause;

void printParticipant(Participant participant) {
    printf("Participant: %s %s %s\n", participant.first_name, participant.middle_name, participant.last_name);
    printf("Email: %s\n", participant.email);
    printf("Phone Number: %s\n", participant.phone_number);
}

void printParticipantResponse(ParticipantResponse response) {
    printParticipant(response.participant);
    printf("Will participate: %s\n", response.will_participate ? "Yes" : "No");
}

void printCause(Cause cause) {
    printf("Title: %s\n", cause.title);
    printf("Description: %s\n", cause.description);
    printf("Date: %d/%d/%d %d:%d\n", cause.date.day, cause.date.month, cause.date.year, cause.date.time.hour, cause.date.time.minute);
    printf("Participants:\n");
    for (int i = 0; i < cause.num_participants; ++i) {
        printf("Participant %d:\n", i + 1);
        printParticipantResponse(cause.participants[i]);
    }
}

int main() {
    Cause cause1 = {
        .title = "Clean-up",
        .description = "Clean up the local park.",
        .date = {.day = 15, .month = 4, .year = 2024, .time = {.hour = 10, .minute = 30}},
        .participants = {
            {.participant = {.first_name = "Boris", .last_name = "Felix", .email = "borisfelix@gmail.com", .phone_number = "123456789"}, .will_participate = 1},
            {.participant = {.first_name = "Mark", .last_name = "Danileichenko", .email = "markdanileichenka@gmail.com", .phone_number = "987654321"}, .will_participate = 0}
        },
        .num_participants = 2
    };

    Cause cause2 = {
        .title = "Fund",
        .description = "Local charity.",
        .date = {.day = 20, .month = 4, .year = 2024, .time = {.hour = 14, .minute = 0}},
        .participants = {
            {.participant = {.first_name = "Svetlio", .last_name = "Johnson", .email = "svetlio@gmail.com", .phone_number = "111222333"}, .will_participate = 1},
            {.participant = {.first_name = "Bob", .last_name = "Bobov", .email = "bob@gmail.com", .phone_number = "444555666"}, .will_participate = 1}
        },
        .num_participants = 2
    };

    printCause(cause1);
    printCause(cause2);

    return 0;
}
