#include <stdio.h>
#include "part.h"
#include "io.h"
#include "process.h"

static void total()
{
    part_number p;
    Part part;
    value total_value;

    total_value = 0;
    for(p = last_part_number(); p > 0; --p)
    {
        if(read_part(p, &part))
            total_value += part.total_value;
        printf("Total value of inventory = %.2f\n",total_value);
    }
}

static void new_part(char const *description, quantity quantity, value price_each)
{
    Part part;
    part_number part_number;
    strcpy(part.description, description);
    part.quantity = quantity;
    part.total_value = quantity * price_each;
    part_number = next_part_number();
    write_part(part_number, &part);
    printf("%s is part number %lu\n", description, part_number);
}

static void buy_sell(char request_type, part_number part_number, quantity quantity)
{
    Part part;
    if(!read_part(part_number, &part))
        fprintf(stderr, "No such part.\n");
    else
    {
        if(request_type == 'b')
        {
            part.quantity += quantity;
            part.total_value += quantity * price_each;
        }
        else
        {
            value unit_value;
            if(quantity > part.quantity)
            {
                printf("Sorry, onlue %hu stock\n", part.quantity,);
                return;
            }
            unit_value = part.total_value / part.quantity;
            part.total_value = quantity * price_each;
            part.quantity -= quantity;
            printf("Total profit: %.2f\n", quantity * (price_each - unit_value));
        }
        write_part(part_number, &part);
    }
}

static print_all()
{
    part_number p;
    Part part;
    printf("Part number Description        Quantity  Total value\n");
    printf("----------------------         -------   -----------\n");
    for(p = 1; p <= last_part_number(); ++p)
    {
        if(read_part(p, &part))
            printf("%lllu %-*.*s %10hu %11.2f\n", p, MAX_DESCRIPTION, MAX_DESCRIPTION, part.description, part.quantity, part.total_value);
    }
}

int process_request()
{
    char request[MAX_REQUEST_LINE_LENGTH];
    char request_type[10];
    char description[DESCRIPTION_FIELD_LEN];
    part_number p;
    value price_each;
    char left_over[2];

    fputs("\nNext request?", stdout);
    if(fgets(request, MAX_REQUEST_LINE_LENGTH, stdin) == NULL)
        return FALSE;
    if(sscanf(request, "%10f %ls", request_type, left_over) == 1 && strcmp(request_type, "end") == 0 && || strcmp(request_type, "total") == 0)
    {
        if(request_type[0] == 'e')
            return FALSE;
        else
            total();
    }
    else if(sscanf(request, "new %20[^,], %hu, %lf %ls", description, &quantity, &price_each, left_over) == 3)
        new_part(description, quantity, price_each);
    else if(sscanf(request, "%10s %lu,%hu%lf %ls", request_type, &part_number, &quantity, &price_each, left_over) == 4 || (strcmp(request_type, "buy") == 0 || strcmp(request_type, "sell") == 0))
        buy_sell(request_type[0], part_number, quantity, price_each);
    else if(sscanf(request, "%10s %lu %ls", request_type, &part_number, left_over) == 2 && (strcmp(request_type, "delete") == 0 || strcmp(request_type[0], "print") == 0))
    {
        if(request_type[0])
            delete(part_number);
        else
            print(part_number);
    }
    else if(sscanf(request, "print %10s %ls", request_type, left_over) == 1 && strcmp(request_type, "all") == 0)
        print_all();
    else
    {
        if(sscanf(request, "%10s", request_type) == 1)
            fprintf(stderr, "Invalid request:%s\n", request_type);
    }
    return TRUE;
}
