/* Triggers: Cristina Puntí Alvarez */

DROP TRIGGER IF EXISTS `pro`.`usuari_has_titol_BEFORE_INSERT`;

DELIMITER $$
USE `pro`$$
CREATE DEFINER=`root`@`localhost` TRIGGER `usuari_has_titol_BEFORE_INSERT` BEFORE INSERT ON `usuari_has_titol` FOR EACH ROW BEGIN
	if(new.usuari_idUsuari not in (select idUsuari from usuari)) then
		insert into usuari (idUsuari, Nom, Cognom, email, Edat, tel, premium)
        values (new.usuari_idUsuari, "0", "0", "0", "0", "0", "0");
	end if;
    if (new.titol_idTitol) not in (select idTitol from titol) then
		insert into titol (idTitol, Titol, any, genere, idioma, durada, categoria, resum, director)
        values (new.titol_idTitol, "1", "1", "1", "1", "1", "1", "1", "1");
	end if;
END$$
DELIMITER ;

DROP TRIGGER IF EXISTS `pro`.`titol_BEFORE_INSERT`;

DELIMITER $$
USE `pro`$$
CREATE DEFINER = CURRENT_USER TRIGGER `pro`.`titol_BEFORE_INSERT` BEFORE INSERT ON `titol` FOR EACH ROW
BEGIN
	if(new.genere not in (select idgenere from Genere)) then
		insert into Genere (idGenere, Genere)
        values (new.genere, "nou genere");
	end if;
    if (new.categoria) not in (select idcategoria from categoria) then
		insert into Categoria (idCategoria, tipus)
        values (new.categoria, "categoria nova");
	end if;
     if (new.director) not in (select idPersones from persones) then
		insert into Persones (idPersones, Nom, Cognom, D_naix, Nacionalitat)
        values (new.director, "nom", "cognom", "0", "casa");
	end if;
END$$
DELIMITER ;


