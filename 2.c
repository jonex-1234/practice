tourism_data = """Kerala,Munnar,Alleppey
Karnataka,Mysuru,Coorg,Hampi
Tamil Nadu,Ooty
Rajasthan,Jaipur,Udaipur,Jaisalmer"""

with open("tourism.txt", "w") as file:
    file.write(tourism_data)
    
    
    
    
    
    
    
tourism = {}


def create_dictionary(filename):

    dictionary = {}

    try:

        file = open(filename, "r")

        for line in file:

            data = line.strip().split(",")

            state = data[0].strip()

            places = []

            for place in data[1:]:
                places.append(place.strip())

            dictionary[state] = places

        file.close()

        return dictionary

    except:

        return None


def search(state_name):

    if state_name in tourism:
        print(state_name, ":", tourism[state_name])

    else:
        print(-1)


def add(state_name, places):

    if state_name in tourism:
        print(-1)

    else:
        tourism[state_name] = places
        
        
        

def update(state_name, places):
    if state_name in tourism:
        for place in places:
            if place not in tourism[state_name]:
                tourism[state_name].append(place)
    else:
        print(-1)
        
        
'''


def update(state_name, places):

    if state_name in tourism:
        tourism[state_name] = places

    else:
        print(-1)
        
        
this is for directly eraseing  the tourism and add fresh one
        
'''
        

        
        
def delete(state_name):

    if state_name in tourism:
        del tourism[state_name]

    else:
        print(-1)


while True:

    operation = input("Enter operation: ")

    data = operation.split(",")

    command = data[0].strip()

    if command == "c":

        result = create_dictionary("tourism.txt")

        if result is None:
            print(-1)

        else:
            tourism = result


    elif command == "s":

        state_name = data[1].strip()

        search(state_name)


    elif command == "a":

        state_name = data[1].strip()

        places = []

        for place in data[2:]:
            places.append(place.strip())

        add(state_name, places)


    elif command == "u":

        state_name = data[1].strip()

        places = []

        for place in data[2:]:
            places.append(place.strip())

        update(state_name, places)


    elif command == "d":

        state_name = data[1].strip()

        delete(state_name)


    elif command == "p":

        if len(tourism) == 0:
            print(-1)

        else:
            print(tourism)


    elif command == "t":

        break


    else:

        print(-1)
