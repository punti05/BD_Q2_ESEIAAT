/* Stored Procedures: Cristina Puntí Alvarez */

USE `pro`;

/* Stored Procedures utilitzats a l'aplicació C++ */

DROP procedure IF EXISTS `esborrar_nous`;
DELIMITER $$
CREATE PROCEDURE esborrar_nous()
BEGIN
	DELETE FROM titol WHERE (idTitol > 15);
END$$
DELIMITER ;

DROP procedure IF EXISTS `reset`;
DELIMITER $$
USE `pro`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `reset`()
BEGIN
	DELETE FROM titol WHERE (idTitol > 15);
    DELETE FROM usuari WHERE (idUsuari > 17);
END$$
DELIMITER ;

/* Stored Procedure amb Cursors: crearpremium() permet convertir tots aquells usuaris que tenen 
	a la seva llista (usuari_has_titol) mes de 2 titols. */

DROP procedure IF EXISTS `crearpremium`;
DELIMITER $$
USE `pro`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `crearpremium`()
BEGIN
	DECLARE hay_filas INT DEFAULT true;
	DECLARE user, num int;
    
	DECLARE cur1 CURSOR FOR select 
				Usuari_idUsuari, count(*) from usuari_has_titol group by Usuari_idUsuari;
                                
	DECLARE continue HANDLER FOR NOT FOUND SET hay_filas=false;
	
    OPEN cur1;
	FETCH cur1 INTO user, num;
	
    while (hay_filas) DO
	if (num >= 2) then
        UPDATE usuari
        SET premium = 1 WHERE (usuari.idUsuari = user and num >= 2);
	end if;
    FETCH cur1 INTO user, num;
    end while;
    
	CLOSE cur1;

END$$

DELIMITER ;

/* "Crida" de les funcions */

call esborrar_nous();
call reset();
call crearpremium();

