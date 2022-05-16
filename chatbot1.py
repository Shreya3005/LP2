import random

user_name = input("Bot: By what name you want me to call you?")  # Taking the name of User

bot_template = "Bot: {0}"
user_template = user_name+": {0}"

bot_name = "Canteen buddy"  # Statically assign the name of chat bot

responses = {
    "what's your name ?":
    [
        "My name is {0}".format(bot_name),
        "People used to call me {0}".format(bot_name),
        "I usually go by {0}".format(bot_name)
    ],
    "what's the time of canteen ?":
    [
        "The time of PICT canteen is :- \n Morning 8:00 am to 2:00 pm\n Evening 6:30 pm to 9:00 pm"
    ],
    "what's the fees of canteen ?":
    [
        "The fees of canteen is approximately 60000 per year which is added in the hostel fees.\nWhile on daily \
basis it is dependent on the menu and is at max 100 - 120 rupees per plate. "
    ],
    "is canteen open on sunday ?":
    [
        "Yes, It is open in morning but closed in evening."
    ],
    "is breakfast included in hostel fees ?":
    [
        "No, It is not included it just contains the lunch and dinner.\n But, If you want the breakfast you can pay \
        and have it.."
    ],
    "": 
    [ 
        "Hey! Are you there?", 
        "What do you mean by saying nothing?", 
        "Sometimes saying nothing tells a lot :)",
    ],
    "default": 
    [
        "this is a default message"
    ] 

}


def respond(message):
    if message in responses: 
        bot_message = random.choice(responses[message])
    else: 
        bot_message = random.choice(responses["default"])
    return bot_message


def related(x_text):   # keyword
    if "name" in x_text: 
        y_text = "what's your name ?"
        
    elif "time" in x_text and "canteen" in x_text: 
        y_text = "what's the time of canteen ?"
    elif "fees" in x_text and "canteen" in x_text:
        y_text = "what's the fees of canteen ?"
        
    elif "open" in x_text and "sunday" in x_text: 
        y_text = "is canteen open on sunday ?"
    elif "breakfast" in x_text and "included" in x_text and "fees" in x_text: 
        y_text = "is breakfast included hostel fees ?"
    else: 
        y_text = ""
    return y_text


def send_message(message):
    print(user_template.format(message))
    response = respond(message)
    print(bot_template.format(response))


while 1:
    my_input = input()
    my_input = my_input.lower()
    if my_input == "exit" or my_input == "stop" or my_input == "bye":
        break
    related_text = related(my_input)
    send_message(related_text)
    
