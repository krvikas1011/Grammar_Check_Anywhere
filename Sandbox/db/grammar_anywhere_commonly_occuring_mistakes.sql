use grammar_anywhere;

DROP TABLE IF EXISTS `commonly_occuring_mistakes`;
CREATE TABLE `commonly_occuring_mistakes` (
  `uid` varchar(20) NOT NULL,
  `word_error` varchar(20) NOT NULL,
  `sentence_error` varchar(200) NOT NULL,
  PRIMARY KEY (`uid`),
  UNIQUE KEY `uid_UNIQUE` (`uid`),
  CONSTRAINT `FKCOM_uid` FOREIGN KEY (`uid`) REFERENCES `users` (`uid`)
)