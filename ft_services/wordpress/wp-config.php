<?php

define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'admin' );
define( 'DB_PASSWORD', 'urdaddyduty' );
define( 'DB_HOST', 'wildboar-mysql-service' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE',  '');
define( 'WP_DEBUG', false );
define( 'AUTH_KEY',         'D[E;5b?~zd7%5sHiRVc*7gh&I-KKGA%xi|y%N`$IHT~bU^8ZiOmMLzY<FNY;$R7V' );
define( 'SECURE_AUTH_KEY',  'tA~ L(T^Bad<%ZEab+U&/gz&cRy9-^8.yz,Bw>cNms_-oyBDG+D7 05%$n~[7#d=' );
define( 'LOGGED_IN_KEY',    'k3X9(YNgA;.a<BhP_X:ymU)pK$>zn$hra-b$r-K-Gcwk<uJ/Tz=jA*/E]Mt{gDux' );
define( 'NONCE_KEY',        'pLym=t-/PYe@OIPBc^/t)}XI,Rmj`NMy}ACha4<ay#go5BaX]J?ppOYE$`#|V-VA' );
define( 'AUTH_SALT',        '}`BmkH80wE@|az|;j~E ia<6+x(4tE7R&z_%g-:,$xr-Ok{|5XZxJuqJiSx:P0ix' );
define( 'SECURE_AUTH_SALT', '?8NkhBl,AR#P|Dl,-BqE-~dpPk9kti@h8B#4q/z(n`A4X4+=9Se4g-w)[nNKM#X{' );
define( 'LOGGED_IN_SALT',   'xGA1*Jr0yXL|EEeyr4]W:3HC+m]KLnhD##|3*!=2K}sXQbfIg7 8D[%1y&N=e0bg' );
define( 'NONCE_SALT',       'p> T>[*;tA:viO<V}Op u`Xt|)rT+^Z>a=?GFxc1f!t2rF24tJMRW$leq`iM]Zll' );
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', '/var/www/wordpress/' . '/' );
}
$table_prefix = 'wp_';
require_once ABSPATH . 'wp-settings.php';
