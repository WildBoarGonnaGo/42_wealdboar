<?php
# Add lchantel as author user
add_action( 'init', function () {
  
	$username = 'lchantel';
	$password = 'lchantel';
	$email_address = 'lchantel@student.21-school.ru';

	if ( ! username_exists( $username ) ) {
		$user_id = wp_create_user( $username, $password, $email_address );
		$user = new WP_User( $user_id );
		$user->set_role( 'author' );
	}
	
} );
# Add jbelinda as author user
add_action( 'init', function () {
  
	$username = 'jbelinda';
	$password = 'jbelinda';
	$email_address = 'jbelinda@student.21-school.ru';

	if ( ! username_exists( $username ) ) {
		$user_id = wp_create_user( $username, $password, $email_address );
		$user = new WP_User( $user_id );
		$user->set_role( 'author' );
	}
	
} );
# Add pstein as author user
add_action( 'init', function () {

	$username = 'pstein';
	$password = 'pstein';
	$email_address = 'pstein@student.21-school.ru';

	if ( ! username_exists( $username ) ) {
		$user_id = wp_create_user( $username, $password, $email_address );
		$user = new WP_User( $user_id );
		$user->set_role( 'author' );
	}

} );
