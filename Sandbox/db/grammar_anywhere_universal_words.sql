use grammar_anywhere;

CREATE TABLE `universal_words` (
  `word` varchar(30) NOT NULL,
  `count_of_users` integer(20) NOT NULL,
  PRIMARY KEY (`word`),
  UNIQUE KEY `word_UNIQUE` (`word`)
)