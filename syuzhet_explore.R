library(syuzhet)

# load sentiment/emotion dictionaries for checking
nrc = get_sentiment_dictionary("nrc")
bing = get_sentiment_dictionary("bing")
afinn = get_sentiment_dictionary("afinn")
syu = get_sentiment_dictionary("syuzhet")

# go through and mess with them
selected_dict = syu

selected_dict[which(selected_dict$word == "abundance"),] #
selected_dict[which(selected_dict$word == "code"),]
selected_dict[which(selected_dict$word == "core"),]
selected_dict[which(selected_dict$word == "apple"),]
selected_dict[which(selected_dict$word == "apply"),]
selected_dict[which(selected_dict$word == "applied"),]
selected_dict[which(selected_dict$word == "applicable"),]
selected_dict[which(selected_dict$word == "application"),]
selected_dict[which(selected_dict$word == "drive"),]
selected_dict[which(selected_dict$word == "driven"),]
selected_dict[which(selected_dict$word == "determined"),]
selected_dict[which(selected_dict$word == "salty"),]
selected_dict[which(selected_dict$word == "joyful"),] #
selected_dict[which(selected_dict$word == "mathematics"),]
selected_dict[which(selected_dict$word == "math"),]
selected_dict[which(selected_dict$word == "school"),]
selected_dict[which(selected_dict$word == "education"),]
selected_dict[which(selected_dict$word == "educate"),]
selected_dict[which(selected_dict$word == "educa"),]
selected_dict[which(selected_dict$word == "educational"),]
selected_dict[which(selected_dict$word == "university"),]
selected_dict[which(selected_dict$word == "glory"),] #

selected_dict[which(selected_dict$word == "falling"),]
selected_dict[which(selected_dict$word == "futuristic"),]
selected_dict[which(selected_dict$word == "future"),]

selected_dict[which(selected_dict$word == "jaded"),]
selected_dict[which(selected_dict$word == "faded"),]
selected_dict[which(selected_dict$word == "faint"),]

selected_dict[which(selected_dict$word == "vehicle"),]
selected_dict[which(selected_dict$word == "vehicular"),]
selected_dict[grepl("auto",selected_dict$word),] # there's autonomous