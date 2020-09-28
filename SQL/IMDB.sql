/* IMDB: Cristina Puntí Alvarez */

-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema Pro
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema Pro
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS Pro;
CREATE SCHEMA IF NOT EXISTS `Pro` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `Pro` ;

-- -----------------------------------------------------
-- Table `Pro`.`Genere`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Genere` (
  `idGenere` INT NOT NULL COMMENT '',
  `Genere` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idGenere`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Categoria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Categoria` (
  `idCategoria` INT NOT NULL COMMENT '',
  `Tipus` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idCategoria`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Titol`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Titol` (
  `idTitol` INT NOT NULL COMMENT '',
  `Titol` VARCHAR(45) NULL COMMENT '',
  `Any` INT NULL COMMENT '',
  `Genere` INT NULL COMMENT '',
  `Idioma` VARCHAR(45) NULL COMMENT '',
  `Durada` INT NULL COMMENT '',
  `Categoria` INT NULL COMMENT '',
  `Resum` VARCHAR(45) NULL COMMENT '',
  `Director` INT NULL COMMENT '',
  PRIMARY KEY (`idTitol`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Usuari`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Usuari` (
  `idUsuari` INT NOT NULL COMMENT '',
  `Nom` VARCHAR(45) NULL COMMENT '',
  `Cognom` VARCHAR(45) NULL COMMENT '',
  `email` VARCHAR(45) NULL COMMENT '',
  `Edat` INT NULL COMMENT '',
  `Tel` INT NULL COMMENT '',
  `Premium` TINYINT(1) NULL COMMENT '',
  PRIMARY KEY (`idUsuari`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Usuari_has_Titol`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Usuari_has_Titol` (
  `Usuari_idUsuari` INT NOT NULL COMMENT '',
  `Titol_idTitol` INT NOT NULL COMMENT '',
  PRIMARY KEY (`Usuari_idUsuari`, `Titol_idTitol`)  COMMENT '')
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `Pro`.`Productora`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Productora` (
  `idProductora` INT NOT NULL COMMENT '',
  `Nom` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idProductora`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Titol_has_Productora`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Titol_has_Productora` (
  `Titol_idTitol` INT NOT NULL COMMENT '',
  `Productora_idProductora` INT NOT NULL COMMENT '',
  PRIMARY KEY (`Titol_idTitol`, `Productora_idProductora`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Persones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Persones` (
  `idPersones` INT NOT NULL COMMENT '',
  `Nom` VARCHAR(45) NULL COMMENT '',
  `Cognom` VARCHAR(45) NULL COMMENT '',
  `D_naix` DATE NULL COMMENT '',
  `Nacionalitat` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idPersones`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Rol`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Rol` (
  `idRol` INT NOT NULL COMMENT '',
  `Rol` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idRol`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Titol_has_Persones`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Titol_has_Persones` (
  `Titol_idTitol` INT NOT NULL COMMENT '',
  `Persones_idPersones` INT NOT NULL COMMENT '',
  `idRol` INT NOT NULL COMMENT '',
  PRIMARY KEY (`Titol_idTitol`, `Persones_idPersones`, `idRol`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Noticies`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Noticies` (
  `idNoticies` INT NOT NULL COMMENT '',
  `idPersones` INT NULL COMMENT '',
  `Diari` VARCHAR(45) NULL COMMENT '',
  `Noticia` VARCHAR(45) NULL COMMENT '',
  PRIMARY KEY (`idNoticies`)  COMMENT '')
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `Pro`.`Premis`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `Pro`.`Premis` (
  `idPremis` INT NOT NULL COMMENT '',
  `idPersona` INT NULL COMMENT '',
  `Nom` VARCHAR(45) NULL COMMENT '',
  `Tipus` VARCHAR(45) NULL COMMENT '',
  `Año` INT NULL COMMENT '',
  PRIMARY KEY (`idPremis`)  COMMENT '')
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

LOAD DATA INFILE 'C:\\kk\\Categoria.csv'
	INTO TABLE Categoria
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;

;

LOAD DATA INFILE 'C:\\kk\\Genere.csv'
	INTO TABLE Genere
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Noticies.csv'
	INTO TABLE Noticies
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Persones.csv'
	INTO TABLE Persones
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Premis.csv'
	INTO TABLE Premis
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Productora.csv'
	INTO TABLE Productora
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Rol.csv'
	INTO TABLE Rol
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Titol_Has_Persones.csv'
	INTO TABLE Titol_Has_Persones
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Titol_Has_Productora.csv'
	INTO TABLE Titol_Has_Productora
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Titol.csv'
	INTO TABLE Titol
    CHARACTER SET latin1
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Usuari.csv'
	INTO TABLE Usuari
    CHARACTER SET latin1
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

LOAD DATA INFILE 'C:\\kk\\Usuari_Has_Titol.csv'
	INTO TABLE Usuari_Has_Titol
    FIELDS TERMINATED BY ';'     
    OPTIONALLY ENCLOSED BY '"'
    LINES TERMINATED BY '\r\n'
    IGNORE 1 rows;
;

ALTER table Titol
	add constraint foreign key (Genere) references Genere(idGenere);
    
ALTER table titol
	add constraint foreign key (Categoria) references Titol(idTitol);
    
ALTER table Noticies
	add constraint foreign key (idPersones) references Persones(idPersones);
    
ALTER table titol_has_Persones
	add constraint foreign key (idRol) references Rol(idRol);

ALTER table Titol_has_Persones
	add constraint foreign key (Titol_idTitol) references Titol(idTitol);
	
ALTER table Titol_has_Persones
	add constraint foreign key (Persones_idPersones) references Persones(idPersones);
    
ALTER table Titol_has_Productora
	add constraint foreign key (Titol_idTitol) references Titol(idTitol);
    
ALTER table Titol_has_Productora
    add constraint foreign key (Productora_idProductora) references Productora(idProductora);

ALTER table Premis
	add constraint foreign key (idPersona) references Persones(idPersones);  
    
ALTER table Usuari_has_Titol
	add constraint foreign key (Usuari_idUsuari) references Usuari(idUsuari);
    
ALTER table Usuari_has_Titol
	add constraint foreign key (Titol_idTitol) references Titol(idTitol);
